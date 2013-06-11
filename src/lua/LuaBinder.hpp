

#pragma once
#ifndef __SPACEG_LUABINDER__
#define __SPACEG_LUABINDER__

#include <slua/Exception.hpp>
#include <slua/Context.hpp>
#include <slua/Table.hpp>

#include "LuaInterface.hpp"
#include "../base/ObjectStorage.hpp"

#include <iostream>


namespace spaceg {

class LuaGameState;



/**
* Lua Binding Functionality
*/
class LuaBinder
{
private:
	static ObjectStorage<LuaClassPtr> objects_;
	
	LuaGameState& lgstate_;
	slua::Context ctx_;
	
	using ObjectId = ObjectStorage<LuaClassPtr>::ObjectId;
	
public:
	LuaBinder(LuaGameState& state);
	~LuaBinder();
	
	template<class T>
	void registerClass()
	{
		slua::Context& ctx = ctx_;
		registerFuncTable<T>(ctx, true);
		
		//add a create/destroy function to the function table
		
		//global table
		ctx.pushGlobalTable();
		slua::Table global;
		global.setto(ctx, -1);	//access to global table
		
		global.pushField(T::luaInterface.metatableName);
		slua::Table tbl;
		tbl.setto(ctx, -1);
		//pointer to self as closure
		ctx.pushPtr(this);
		ctx.pushClojure(&push_new_object<T>, 1);
		tbl.assignField("create");
		
		//pointer to self as closure
		ctx.pushPtr(this);
		ctx.pushClojure(&delete_object<T>, 1);
		tbl.assignField("delete");
		//destroy function
		
		//global assign again?
		ctx.pop(2); //global + func table	
	}
	
	template<class T>
	void registerObject(const std::shared_ptr<T>& obj, const char* name)
	{
		slua::Context& ctx = ctx_;
		const LuaClassPtr& lo = obj;
		registerFuncTable<T>(ctx, false);
		
		//add object to storage
		auto id = objects_.add();
		//std::cout << "objid: " << id << std::endl;
		objects_.get(id) = obj;
		
		//add the object as global value
		ctx.pushGlobalTable();
        slua::Table global;
		global.setto(ctx, -1);	//access to global table
        ctx.pushString(name);	//name of object
        ctx.pushPtr(reinterpret_cast<void*>(id));
		global.assignField();	//assign user data to name
		ctx.pop(1); //pop globaltable
	}
	
	
	static inline const ObjectStorage<LuaClassPtr>& Storage() { return objects_; }
private:

	//inline static protect_table(slua::Context& ctx);

	/**
	* Register function table
	*/
	template<class T>
	inline static void registerFuncTable(slua::Context& ctx, bool createFunc = false)
	{
		static bool registered = false;
		if(registered)
			return;
		
		//global table
		ctx.pushGlobalTable();
		slua::Table global;
		global.setto(ctx, -1);	//access to global table
		
		ctx.pushString(T::luaInterface.metatableName);	//name of object
		
		//functiontable
		ctx.pushTable();
		slua::Table tbl;
		tbl.setto(ctx, -1);
		
		// assign functions
		// for binding in a metatable the metatable requires a __index function
		for (int i = 0; T::luaInterface.functions[i].name; i++) 
		{
			ctx.pushInteger(i);
			ctx.pushClojure(&dispatch<T>, 1); //clojure has internal arguments
			tbl.assignField(T::luaInterface.functions[i].name);
		}
		
		//add a blocking metatable?
		
		global.assignField();
		
		ctx.pop(1); //global table
		registered = true;
	}
	
	template<class T>
	static int push_new_object(lua_State* state)
	{
		slua::Context ctx(state);
		
		void* binderPtr = const_cast<void*>(ctx.getPtr(ctx.upIndex(1)));
		LuaBinder* binder = reinterpret_cast<LuaBinder*>(binderPtr);
		
		//create object
		auto id = objects_.add();
		objects_.get(id) = std::make_shared<T>(binder->lgstate_);

		//std::cout << "ref info " << objects_.get(id).get().refCount() << std::endl;

		//push objectid
		ctx.pushPtr(reinterpret_cast<void*>(id));
		
		//call hook
		
		return 1;
	}
	
	template<class T>
	static int delete_object(lua_State* state)
	{
		slua::Context ctx(state);
		
		if(!ctx.isType(1, slua::LuaType::LIGHTUSERDATA))
			throw slua::LuaException("There seems to be not a lightuserdata (objectid) to dispatch function call");
		
		//pay attention to this
		ObjectId id = static_cast<ObjectId>(reinterpret_cast<long>(const_cast<void*>(ctx.getPtr(1))));
		
		if(!objects_.has(id))
			throw slua::LuaException("not a valid object or already disposed");
		
		//Each type has its own object storage?
		//T::luaInterface.objectStorage
		LuaClassPtr& objptr = objects_.get(id);
		objects_.remove(id); //already detach? O_o
		objptr.reset();
		
		//one parameter
		//object id
		
		//reset objectstorage
		
		return 0;
	}
	
	template<class T>
	static int dispatch(lua_State* state)
	{
		slua::Context ctx(state);
		
		//auto ctx.getState()
		get(state);
		
		//func index
		int funcIndex = ctx.getInteger(ctx.upIndex(1));
		
		if(!ctx.isType(1, slua::LuaType::LIGHTUSERDATA))
			throw slua::LuaException("There seems to be not a lightuserdata (objectid) to dispatch function call");
		
		//pay attention to this
		ObjectId id = static_cast<ObjectId>(reinterpret_cast<long>(const_cast<void*>(ctx.getPtr(1))));
		
		if(!objects_.has(id))
			throw slua::LuaException("not a valid object or already disposed");
		
		//Each type has its own object storage?
		//T::luaInterface.objectStorage
		auto objptr = objects_.get(id);
		
		//std::cout << "receive id:" << id << std::endl;
		
		if(!objptr)
			throw slua::LuaException("not a valid object");

		std::shared_ptr<T> obj = std::static_pointer_cast<T>(objptr);
		return (*obj.*(T::luaInterface.functions[funcIndex].mfunc))(ctx);	
	}
	
	
	static LuaGameState& get(lua_State* state);
	
};
	
} //end namespace spaceg

#endif // __SPACEG_LUABINDER__

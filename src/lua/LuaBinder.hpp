

#pragma once
#ifndef __SPACEG_LUABINDER__
#define __SPACEG_LUABINDER__

#include <slua/LuaObject.hpp>
#include <slua/Exception.hpp>
#include <slua/Context.hpp>
#include <slua/Table.hpp>

#include "LuaInterface.hpp"
#include "../base/ObjectStorage.hpp"




namespace spaceg {

class LuaGameState;



/**
* Lua Binding Functionality
*/
class LuaBinder
{
private:
	static ObjectStorage<slua::LuaObjectPtr> objects_;
	LuaGameState& lgstate_;
	slua::Context& ctx_;
	
	using ObjectId = ObjectStorage<slua::LuaObjectPtr>::ObjectId;
	
public:
	LuaBinder(LuaGameState& state);
	~LuaBinder();
	
	template<class T>
	void registerClass()
	{
		registerMetaTable<T>(ctx_);
		
		if(!(T::luaInterface.constructorName))
			throw slua::LuaException("Missing ctor name");
		
		//creater/constructor function
		ctx_.pushGlobalTable();
		slua::Table global;
		global.setto(ctx_, -1);
		ctx_.pushFunc(&push_new_object<T>);
		global.assignField(T::luaInterface.constructorName);
	}
	
	template<class T>
	void registerObject(const T& obj, const char* name)
	{
		const slua::LuaObject& lo = obj;
		registerMetaTable<T>(ctx_);
		
		//add object to storage
		auto id = objects_.add();
		objects_.get(id) = lo;
		
		ctx_.pushGlobalTable();
        slua::Table global;
		global.setto(ctx_, -1);	//access to global table
        ctx_.pushString(name);	//name of object
        
        ctx_.pushPtr(reinterpret_cast<void*>(id));
		if(ctx_.pushMetaTable(T::luaInterface.metatableName))
			throw slua::LuaException("MetaTable was not created for this type");
		ctx_.assignMetaTable(-2);
        
		global.assignField();	//assign the tbl to name to global table
		ctx_.pop(1); //pop globaltable
	}
	
private:

	/**
	* Register the class metatable to registry
	*/
	template<class T>
	inline static void registerMetaTable(slua::Context& ctx)
	{
		static bool registered = false;
		if(registered)
			return;
			
		slua::Table meta;
		if(!ctx.pushMetaTable(T::luaInterface.metatableName))
			throw slua::LuaException("Already registered metatable with this name");	
		meta.setto(ctx, -1);
		
		//TODO register metatable as index function?
		//register index function
		ctx.pushStringLiteral("__index");
		ctx.pushCopy(meta.getIndex());
		meta.assignField();
		
		// assign functions
		// for binding in a metatable the metatable requires a __index function
		for (int i = 0; T::luaInterface.functions[i].name; i++) 
		{
			ctx.pushInteger(i);
			ctx.pushClojure(&dispatch<T>, 1); //clojure has internal arguments
			meta.assignField(T::luaInterface.functions[i].name);
		}
		
		//protect metatable
		ctx.pushStringLiteral("__metatable");
		ctx.pushBool(false);
		meta.assignField();
			
		//pops the metatable
		ctx.pop(1);

		registered = true;
	}
	
	template<class T>
	static int push_new_object(lua_State* state)
	{
		slua::Context ctx(state);
		
		auto id = objects_.add();
		
		//push id
		objects_.get(id) = new T();
		
		ctx.pushPtr(reinterpret_cast<void*>(id));
		if(ctx.pushMetaTable(T::luaInterface.metatableName))
			throw slua::LuaException("MetaTable was not created for this type");
		ctx.assignMetaTable(-2);
		
		//get id
		//create instance
		//call ctor function
		return 1;
	}
	
	template<class T>
	static int dispatch(lua_State* state)
	{
		slua::Context ctx(state);
		
		//func index
		int funcIndex = ctx.getInteger(ctx.upIndex(1));
		
		if(!ctx.isType(1, slua::LuaType::LIGHTUSERDATA))
			throw slua::LuaException("There seems to be not a lightuserdata (objectid) to dispatch function call");
		
		//pay attention to this
		ObjectId id = static_cast<ObjectId>(reinterpret_cast<long>(const_cast<void*>(ctx.getPtr(1))));
		
		if(!objects_.has(id))
			throw slua::LuaException("not a valid object or already disposed");
		
		auto objptr = objects_.get(id);
		
		if(!objptr.valid())
			throw slua::LuaException("not a valid object");
		
		T& obj = static_cast<T&>(objptr.get());
		return (obj.*(T::luaInterface.functions[funcIndex].mfunc))(ctx);	
	}
	
};
	
} //end namespace spaceg

#endif // __SPACEG_LUABINDER__

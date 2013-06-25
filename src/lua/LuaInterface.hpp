

#pragma once
#ifndef __SPACEG_LUAINTERFACE_HPP__
#define __SPACEG_LUAINTERFACE_HPP__

#include <memory>

namespace slua { class Context; }

namespace spaceg {
	
/*
* { "bar", &Foo::bar }
*/
template<class T>
struct LuaBindFunction
{
    const char *name;
    int(T::*mfunc)(slua::Context&);
};

/**
* Binding Interface for Classes
*/
template<class T>
struct LuaBindInterface
{
	const char* metatableName;
	//const char* constructorName;
	const LuaBindFunction<T> registerHook;
	const LuaBindFunction<T>* functions;
	//static functions?
	//objectStorage
};



class LuaClass;
typedef std::shared_ptr<LuaClass> LuaClassPtr;

class LuaClass : public std::enable_shared_from_this<LuaClass>
{
	
	inline operator LuaClassPtr () { return shared_from_this(); }
	
	
	//virtual const char* metaTable() const = 0;
	//virtual const LuaBindInterfaceCheck& getCheckInterface() = 0;
	//compare
};


	
	
} //end namespace spaceg



#endif //__SPACEG_LUAINTERFACE_HPP__

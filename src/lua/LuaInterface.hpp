

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
	//objectStorage
};



class LuaClass;
typedef std::shared_ptr<LuaClass> LuaClassPtr;

class LuaClass : public std::enable_shared_from_this<LuaClass>
{
	
	inline operator LuaClassPtr () { return shared_from_this(); }
};


	
	
} //end namespace spaceg



#endif //__SPACEG_LUAINTERFACE_HPP__



#pragma once
#ifndef __SPACEG_LUAINTERFACE_HPP__
#define __SPACEG_LUAINTERFACE_HPP__

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
	const char* constructorName;
	const LuaBindFunction<T> registerHook;
	const LuaBindFunction<T>* functions;
};
	
	
} //end namespace spaceg



#endif //__SPACEG_LUAINTERFACE_HPP__

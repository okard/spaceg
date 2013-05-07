
#pragma once
#ifndef __SPACEG_LUAINPUT__
#define __SPACEG_LUAINPUT__

#include <slua/Bind.hpp>

namespace spaceg {

class LuaInput 
{

public:
	static void reg(slua::Context& ctx);
	static int getMousePosition(lua_State* L);
	static int isPressedMBL(lua_State* L);
	static int isPressedMBR(lua_State* L);
	
	
	//Binding Information
	static const slua::BindStatus<LuaInput> bindStatus;
};


} //end namespace spaceg


#endif // __SPACEG_LUAINPUT__

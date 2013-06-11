
#pragma once
#ifndef __SPACEG_LUAINPUT__
#define __SPACEG_LUAINPUT__

#include "LuaInterface.hpp"


namespace spaceg {
	
class LuaGameState;
class Application;

class LuaInput : public LuaClass
{
private:
	LuaGameState& lgstate_;
	Application& app_;

public:
	LuaInput(LuaGameState& lgstate);
	~LuaInput();

	int getMousePosition(slua::Context& ctx);
	int isPressedMBL(slua::Context& ctx);
	int isPressedMBR(slua::Context& ctx);
	
public:
	static const LuaBindInterface<LuaInput> luaInterface;
};


} //end namespace spaceg


#endif // __SPACEG_LUAINPUT__

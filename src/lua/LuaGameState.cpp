

#include "LuaGameState.hpp"

#include <slua/Context.hpp>

using namespace spaceg;


LuaGameState::LuaGameState()
{
}


LuaGameState::~LuaGameState()
{
}

void LuaGameState::loadFile(const char* const fileName)
{
	luaState_.LoadFile(fileName);
	luaState_.Execute();
}
	
		
void LuaGameState::registerLuaInterface()
{
	slua::Bind::Class<EngineContext>(luaState_);
}

//Call "main" Function in Lua File
void LuaGameState::callMain()
{
	slua::Context ctx = luaState_;
	ctx.pushGlobal("main");
	ctx.call(0,0);
}



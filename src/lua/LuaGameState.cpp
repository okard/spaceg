

#include "LuaGameState.hpp"



using namespace spaceg;


LuaGameState::LuaGameState()
{
}

LuaGameState::LuaGameState(const char* const fileName)
{
	luaState_.LoadFile(fileName);
	

}

LuaGameState::~LuaGameState()
{
}

void LuaGameState::reg()
{
	slua::Bind::Class<EngineContext>(luaState_);
}



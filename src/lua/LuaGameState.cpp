

#include "LuaGameState.hpp"



using namespace spaceg;


LuaGameState::LuaGameState()
{
}

LuaGameState::LuaGameState(const char* const fileName)
{
	luaState_.LoadFile(fileName);
	
	//slua::Bind::Class<EngineContext>(luaState_.getContext());
}

LuaGameState::~LuaGameState()
{
}

void LuaGameState::reg()
{

}





#include "LuaGameState.hpp"



using namespace spaceg;

/* //{ "foo", &Foo::foo }, */
const slua::RegStatus<LuaGameState> LuaGameState::Bind = 
{
	.className = "GameState",
	.Functions = 
	{
		{"getUISystem", &LuaGameState::getUISystem},
		{0,0}
	}
};




LuaGameState::LuaGameState()
{
}

LuaGameState::LuaGameState(const char* const fileName)
{
	slua::Bind::Class<LuaGameState>(luaState_.getContext());
}

LuaGameState::~LuaGameState()
{
}

void LuaGameState::reg()
{

}

int LuaGameState::getUISystem(slua::Context& ctx)
{
	return 0;
}	




#include "LuaInput.hpp"

#include <SFML/Window/Mouse.hpp>
#include <slua/Table.hpp>

#include "LuaGameState.hpp"
#include "../Application.hpp"
#include "../GameException.hpp"

using namespace spaceg;


//Functions to bind
static const LuaBindFunction<LuaInput> lua_functions[]=
{
	//{"loadTexture", &LuaSpriteEntity::loadTexture},
	{0,0}
};

//function context
const LuaBindInterface<LuaInput> LuaInput::luaInterface = 
{
	.metatableName = "Input",
	//.constructorName = nullptr,
	.registerHook = {nullptr, nullptr},
	.functions = lua_functions	
};

LuaInput::LuaInput(LuaGameState& lgstate)
	: lgstate_(lgstate)
	, app_(lgstate.getApplication())
{
}

LuaInput::~LuaInput()
{
}


int LuaInput::getMousePosition(slua::Context& ctx)
{	
	auto target = app_.getRenderTarget();
	auto pos = app_.getMousePositionForRenderTarget();
	ctx.pushFloat(pos.x);
	ctx.pushFloat(pos.y);
	//check if is in View?
	return 2;
}

int LuaInput::isPressedMBL(slua::Context& ctx)
{
}

int LuaInput::isPressedMBR(slua::Context& ctx)
{
}

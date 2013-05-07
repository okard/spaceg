

#include "LuaInput.hpp"

#include <SFML/Window/Mouse.hpp>
#include <slua/Table.hpp>

#include "LuaUtil.hpp"
#include "../Application.hpp"

using namespace spaceg;

//Functions to bind
static const slua::BindFunction<LuaInput> functions[]=
{
	//{"loadTexture", &LuaSpriteEntity::loadTexture},
	{0,0}
};

//function context
const slua::BindStatus<LuaInput> LuaInput::bindStatus = 
{
	.className = "Input",
	.Functions = functions	
};


void LuaInput::reg(slua::Context& ctx)
{
	//slua::Bind::Object(ctx, this, "Input");
	
	ctx.pushGlobalTable();
	slua::Table global;
	global.setto(ctx, -1);
	ctx.pushFunc(&LuaInput::getMousePosition);
	global.assignField("getMousePosition");
	
	//ctx.pop(1);
}

int LuaInput::getMousePosition(lua_State* L)
{
	slua::Context ctx(L);
	
	auto target = Application::getInstance().getRenderTarget();
	auto pos = target->mapPixelToCoords(sf::Mouse::getPosition(Application::getInstance().getWindow()), target->getView());
	
	ctx.pushFloat(pos.x);
	ctx.pushFloat(pos.y);
	return 2;
}

int LuaInput::isPressedMBL(lua_State* L)
{
}

int LuaInput::isPressedMBR(lua_State* L)
{
}

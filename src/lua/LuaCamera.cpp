

#include "LuaCamera.hpp"


#include "LuaGameState.hpp"
#include "../Application.hpp"
#include "../GameException.hpp"


using namespace spaceg;


//Functions to bind
static const LuaBindFunction<LuaCamera> lua_functions_cam[]=
{
	//{"loadTexture", &LuaSpriteEntity::loadTexture},
	
	{"getView", &LuaCamera::getView},
	{"zoom", &LuaCamera::zoom},
	{"move", &LuaCamera::move},
	{"rotate", &LuaCamera::rotate},
	{"onChange", &LuaCamera::onChange},
	{0,0}
};

//function context
const LuaBindInterface<LuaCamera> LuaCamera::luaInterface = 
{
	.metatableName = "Camera",
	//.constructorName = nullptr,
	.registerHook = {nullptr, nullptr},
	.functions = lua_functions_cam
};


LuaCamera::LuaCamera(LuaGameState& lgstate)
	: lgstate_(lgstate)
	, app_(lgstate.getApplication())
	, onChangeFunc_(lgstate_.getLuaState())
{
	
}

LuaCamera::~LuaCamera()
{
}
	
int LuaCamera::getView(slua::Context& ctx)
{
	const sf::View& view = app_.getView();
	auto size = view.getSize();
	auto center = view.getCenter();
	
	//TODO think about rotation?
	
	//the sfml view only delivers center and width and height not the corner
	ctx.pushFloat(center.x - (size.x/2.f));
	ctx.pushFloat(center.y - (size.y/2.f));
	ctx.pushFloat(size.x);
	ctx.pushFloat(size.y);
	return 4;
}

int LuaCamera::zoom(slua::Context& ctx)
{
	//Notice 1 is lightuserdata obejct id to class instance
	if(ctx.stackCount() != 2
	|| !ctx.isType(2, slua::LuaType::NUMBER))
		throw GameException("Invalid call of LuaCamera::zoom require 1 number arguments");
		
	app_.getView().zoom(ctx.getFloat(2));
	fireUpdate();
	return 0;
} 

int LuaCamera::rotate(slua::Context& ctx)
{
	//Notice 1 is lightuserdata obejct id to class instance
	if(ctx.stackCount() != 2
	|| !ctx.isType(2, slua::LuaType::NUMBER))
		throw GameException("Invalid call of LuaCamera::rotate require 1 number arguments");
		
	app_.getView().rotate(ctx.getFloat(2));
	fireUpdate();
	return 0;
}

int LuaCamera::move(slua::Context& ctx)
{
	//Notice 1 is lightuserdata obejct id to class instance
	if(ctx.stackCount() != 3
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER))
		throw GameException("Invalid call of LuaCamera::move require 2 number arguments");
		
	
	app_.getView().move(ctx.getFloat(2), ctx.getFloat(3));
	fireUpdate();
	return 0;
}

int LuaCamera::onChange(slua::Context& ctx)
{
	if(ctx.stackCount() != 2
	|| !ctx.isType(2, slua::LuaType::FUNCTION))
		throw GameException("Invalid call of LuaCamera::onChange require 1 function argument");
		
	ctx.pushCopy(2);
	onChangeFunc_.set();
	return 0;
}

void LuaCamera::fireUpdate()
{
	if(onChangeFunc_.isSet())
	{
		onChangeFunc_.push();
		lgstate_.getLuaState().getContext().call(0,0);
	}
}



#include "LuaCamera.hpp"


#include "LuaGameState.hpp"
#include "../Application.hpp"


using namespace spaceg;


//Functions to bind
static const LuaBindFunction<LuaCamera> lua_functions[]=
{
	//{"loadTexture", &LuaSpriteEntity::loadTexture},
	{0,0}
};

//function context
const LuaBindInterface<LuaCamera> LuaCamera::luaInterface = 
{
	.metatableName = "Camera",
	.constructorName = nullptr,
	.registerHook = {nullptr, nullptr},
	.functions = lua_functions	
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
	
	

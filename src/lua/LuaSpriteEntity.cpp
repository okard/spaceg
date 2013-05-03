
#include "LuaSpriteEntity.hpp"

#include "../GameException.hpp"
#include "../ResourceManager.h"
#include "../Application.hpp"

using namespace spaceg;

//Functions to bind
static const slua::BindFunction<LuaSpriteEntity> functions[]=
{
	{"loadTexture", &LuaSpriteEntity::loadTexture},
	{"loadFragmentShader", &LuaSpriteEntity::loadFragmentShader},
	{"loadVertexShader", &LuaSpriteEntity::loadVertexShader},
	{"render", &LuaSpriteEntity::render},
	{0,0}
};

//function context
const slua::BindStatus<LuaSpriteEntity> LuaSpriteEntity::bindStatus = 
{
	.className = "Sprite",
	.Functions = functions	
};

LuaSpriteEntity::LuaSpriteEntity()
	: states_(&shader_)
{
	//can safe a lua ref need constructor function? call LuaObjectCreate()
}

LuaSpriteEntity::~LuaSpriteEntity()
{
}
	
	

//load texture for sprite
int LuaSpriteEntity::loadTexture(slua::Context& ctx)
{
	//TODO set lua_error
	if(ctx.stackCount() != 2)
		throw GameException("Invalid call of Sprite::loadTexture require 1 string argument");
	
	auto tex = TexResMng::getInstance().retrieve(ctx.getString(2));
	sprite_.setTexture ((*tex), true);
	
	return 0;
}


int LuaSpriteEntity::loadFragmentShader(slua::Context& ctx)
{
	if(ctx.stackCount() != 2)
		throw GameException("Invalid call of Sprite::loadFragmentShader require 1 string argument");
	
	shader_.loadFromFile (ctx.getString(2), sf::Shader::Type::Fragment);
	return 0;
}

int LuaSpriteEntity::loadVertexShader(slua::Context& ctx)
{
	if(ctx.stackCount() != 2)
		throw GameException("Invalid call of Sprite::loadVertexShader require 1 string argument");
	
	shader_.loadFromFile (ctx.getString(2), sf::Shader::Type::Vertex);
	return 0;
}
	
int LuaSpriteEntity::render(slua::Context& ctx)
{
	//TODO retrieve Application instance over lua_State?
	//draw sprite
	Application::getInstance().getRenderTarget()->draw(sprite_, states_);
	return 0;
}



//RenderTarget.draw draw (const Drawable &drawable, const RenderStates &states=RenderStates::Default)



	//EngineContext::getInstancePtr()->draw(sprite_);
	
	
	

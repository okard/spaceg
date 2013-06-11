
#include "LuaSpriteEntity.hpp"
#include "LuaUtil.hpp"

#include "../GameException.hpp"
#include "../ResourceManager.h"
#include "../Application.hpp"

#include "../Log.hpp"
#include "../utils/Math.hpp"

using namespace spaceg;

//Functions to bind
static const LuaBindFunction<LuaSpriteEntity> lua_functions[]=
{
	//{"loadTexture", &LuaSpriteEntity::loadTexture},
	{"loadTexture", &LuaSpriteEntity::loadTexture},
	{"loadFragmentShader", &LuaSpriteEntity::loadFragmentShader},
	{"loadVertexShader", &LuaSpriteEntity::loadVertexShader},
	{"render", &LuaSpriteEntity::render},
	{"setSize", &LuaSpriteEntity::setSize},
	{"setPosition", &LuaSpriteEntity::setPosition},
	{"setTextureRect", &LuaSpriteEntity::setTextureRect},
	{"moveTextureRect", &LuaSpriteEntity::moveTextureRect},
	{"setColor", &LuaSpriteEntity::setColor},
	{0,0}
};

//function context
const LuaBindInterface<LuaSpriteEntity> LuaSpriteEntity::luaInterface = 
{
	.metatableName = "Sprite",
	//.constructorName = nullptr,
	.registerHook = {nullptr, nullptr},
	.functions = lua_functions	
};


//Functions to bind
static const slua::BindFunction<LuaSpriteEntity> functions[]=
{
	{"loadTexture", &LuaSpriteEntity::loadTexture},
	{"loadFragmentShader", &LuaSpriteEntity::loadFragmentShader},
	{"loadVertexShader", &LuaSpriteEntity::loadVertexShader},
	{"render", &LuaSpriteEntity::render},
	{"setSize", &LuaSpriteEntity::setSize},
	{"setPosition", &LuaSpriteEntity::setPosition},
	{"setTextureRect", &LuaSpriteEntity::setTextureRect},
	{"moveTextureRect", &LuaSpriteEntity::moveTextureRect},
	{"setColor", &LuaSpriteEntity::setColor},
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
	//register lua object to storage
}

LuaSpriteEntity::~LuaSpriteEntity()
{
}
	
	

//load texture for sprite
int LuaSpriteEntity::loadTexture(slua::Context& ctx)
{
	#if true
	//TODO set lua_error
	if(ctx.stackCount() != 2 || !ctx.isType(2, slua::LuaType::STRING))
		throw GameException("Invalid call of Sprite::loadTexture require 1 string argument");
	#endif
	
	auto tex = TexResMng::getInstance().retrieve(ctx.getString(2));
	tex->setRepeated(true);
	tex->setSmooth(true);
	sprite_.setTexture ((*tex));
	
	return 0;
}

int LuaSpriteEntity::setColor(slua::Context& ctx)
{
	if(ctx.stackCount() != 5
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER)
	|| !ctx.isType(4, slua::LuaType::NUMBER)
	|| !ctx.isType(5, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::setTextureRect require 4 number arguments");
	
	auto r = clamp(ctx.getInteger(2), 0, 255);
	auto g = clamp(ctx.getInteger(3), 0, 255);
	auto b = clamp(ctx.getInteger(4), 0, 255);
	auto a = clamp(ctx.getInteger(5), 0, 255);
	
	sprite_.setColor(sf::Color(r,g,b,a));
	
	return 0;
}

//set the position of the sprite
int LuaSpriteEntity::setPosition(slua::Context& ctx)
{
	if(ctx.stackCount() != 3 
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::setPosition require 2 number arguments");
		
	sprite_.setPosition(ctx.getFloat(2), ctx.getFloat(3));
	return 0;
}

//set the size relativ to view for sprite
int LuaSpriteEntity::setSize(slua::Context& ctx)
{
	if(ctx.stackCount() != 3 
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::setSize require 2 number arguments");
	
	/*
	//auto gbounds = sprite_.getGlobalBounds();
	auto lbounds = sprite_.getLocalBounds();

	float scalex = luaInt2Float(ctx.getInteger(2)) / lbounds.width;
	float scaley = luaInt2Float(ctx.getInteger(3)) / lbounds.height;
	
	cul::Log::Source().verbose("[LuaSpriteEntity::setSize] Scale: %f, %f", scalex, scaley);
	
	sprite_.scale(scalex, scaley);
	*/
	
	sprite_.setSize(ctx.getFloat(2), ctx.getFloat(3));
	return 0;
}

//set the texture rect
int LuaSpriteEntity::setTextureRect(slua::Context& ctx)
{
	if(ctx.stackCount() != 5
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER)
	|| !ctx.isType(4, slua::LuaType::NUMBER)
	|| !ctx.isType(5, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::setTextureRect require 4 number arguments");
	
	auto x = ctx.getFloat(2);
	auto y = ctx.getFloat(3);
	auto width = ctx.getFloat(4);
	auto height = ctx.getFloat(5);
	
	cul::Log::Source().verbose("[LuaSpriteEntity::setTextureRect]: %d, %d, %d, %d", x, y, width, height);

	//todo fix design mistakes of sf::Sprite
	//save the current size of the sprite
	//get the texture size
	// calc out the scale/and other fixes
	
	auto rect = sf::FloatRect(x,y, width, height);
	sprite_.setTextureRect(rect);
	return 0;
}

int LuaSpriteEntity::loadFragmentShader(slua::Context& ctx)
{
	if(ctx.stackCount() != 2 || !ctx.isType(2, slua::LuaType::STRING))
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

int LuaSpriteEntity::moveTextureRect(slua::Context& ctx)
{
	if(ctx.stackCount() != 3 
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::moveTexture require 2 number arguments");
		
	float xmove = ctx.getFloat(2);
	float ymove = ctx.getFloat(3);
	
	//normalize with texture size
	
	auto texrec = sprite_.getTextureRect();
	texrec.left += xmove;
	texrec.top += ymove;
	
	//if width == texture.width add textrec.top > width then textrec.left = 0
	
	//texrec.width += xmove;
	//texrec.height += ymove;
	sprite_.setTextureRect(texrec);
	return 0;
}
	
int LuaSpriteEntity::render(slua::Context& ctx)
{
	//TODO retrieve Application instance over lua_State?
	//draw sprite
	Application::getInstance().getRenderTarget()->draw(sprite_);
	//include states_
	return 0;
}



//RenderTarget.draw draw (const Drawable &drawable, const RenderStates &states=RenderStates::Default)



	//EngineContext::getInstancePtr()->draw(sprite_);
	
	
	

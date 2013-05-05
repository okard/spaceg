
#include "LuaSpriteEntity.hpp"
#include "LuaUtil.hpp"

#include "../GameException.hpp"
#include "../ResourceManager.h"
#include "../Application.hpp"

#include "../Log.hpp"

using namespace spaceg;

//Functions to bind
static const slua::BindFunction<LuaSpriteEntity> functions[]=
{
	{"loadTexture", &LuaSpriteEntity::loadTexture},
	{"loadFragmentShader", &LuaSpriteEntity::loadFragmentShader},
	{"loadVertexShader", &LuaSpriteEntity::loadVertexShader},
	{"render", &LuaSpriteEntity::render},
	{"getViewport", &LuaSpriteEntity::getViewport},
	{"setSize", &LuaSpriteEntity::setSize},
	{"setPosition", &LuaSpriteEntity::setPosition},
	{"setTextureRect", &LuaSpriteEntity::setTextureRect},
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
	if(ctx.stackCount() != 2 || !ctx.isType(2, slua::LuaType::STRING))
		throw GameException("Invalid call of Sprite::loadTexture require 1 string argument");
	
	auto tex = TexResMng::getInstance().retrieve(ctx.getString(2));
	tex->setRepeated(true);
	tex->setSmooth(true);
	sprite_.setTexture ((*tex));
	
	return 0;
}

//set the position of the sprite
int LuaSpriteEntity::setPosition(slua::Context& ctx)
{
	if(ctx.stackCount() != 3 
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::setPosition require 2 number arguments");
		
		
	sprite_.setPosition(luaInt2Float(ctx.getInteger(2)), luaInt2Float(ctx.getInteger(3)));
	
}

//set the size relativ to view for sprite
int LuaSpriteEntity::setSize(slua::Context& ctx)
{
	if(ctx.stackCount() != 3 
	|| !ctx.isType(2, slua::LuaType::NUMBER)
	|| !ctx.isType(3, slua::LuaType::NUMBER))
		throw GameException("Invalid call of Sprite::setSize require 2 number arguments");
	
	//auto target = Application::getInstance().getRenderTarget();
	// sf::RenderTarget::getSize 	( 		)
	//auto size  = target->mapPixelToCoords(sf::Vector2i(sprite_.getGlobalBounds().width, sprite_.getGlobalBounds().height));
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] Test: %d, %d", size.x, size.y);
	
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] RTargetSize: %f, %f", target->getSize().x, target->getSize().y);
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] RViewSize: %f, %f", target->getView().getSize().x, target->getView().getSize().y);
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] RViewCenter: %f, %f", target->getView().getCenter().x, target->getView().getCenter().y);
	
	//the size of the sprite is the pixel count -.- not the realsize
	
	//auto gbounds = sprite_.getGlobalBounds();
	auto lbounds = sprite_.getLocalBounds();
	
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] GBounds: %f, %f,  %f, %f", gbounds.left, gbounds.top, gbounds.width, gbounds.height);
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] LBounds: %f, %f,  %f, %f", lbounds.left, lbounds.top, lbounds.width, lbounds.height);
	
	float scalex = luaInt2Float(ctx.getInteger(2)) / lbounds.width;
	float scaley = luaInt2Float(ctx.getInteger(3)) / lbounds.height;
	
	//cul::Log::Source().verbose("[LuaSpriteEntity::setSize] Param: %f, %f", luaInt2Float(ctx.getInteger(2)), luaInt2Float(ctx.getInteger(3)));
	cul::Log::Source().verbose("[LuaSpriteEntity::setSize] Scale: %f, %f", scalex, scaley);
	
	sprite_.scale(scalex, scaley);
}


//return the current view as x,y,w,h
int LuaSpriteEntity::getViewport(slua::Context& ctx)
{
	auto view = Application::getInstance().getRenderTarget()->getView();
	auto size = view.getSize();
	auto center = view.getCenter();
	
	//the sfml view only delivers center and width and height not the corner
	ctx.pushInteger(luaFloat2Int(center.x - (size.x/2.f)));
	ctx.pushInteger(luaFloat2Int(center.y - (size.y/2.f)));
	ctx.pushInteger(luaFloat2Int(size.x));
	ctx.pushInteger(luaFloat2Int(size.y));
	return 4;
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
	
	
	auto x = ctx.getInteger(2);
	auto y = ctx.getInteger(3);
	auto width = ctx.getInteger(4);
	auto height = ctx.getInteger(5);
	
	cul::Log::Source().verbose("[LuaSpriteEntity::setTextureRect]: %d, %d, %d, %d", x, y, width, height);

	//todo fix design mistakes of sf::Sprite
	//save the current size of the sprite
	//get the texture size
	// calc out the scale/and other fixes

	auto rect = sf::IntRect(x,y, width, height);
	sprite_.setTextureRect(rect);
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
	
	
	





#pragma once
#ifndef __SPACEG_LUASPRITEENTITY__
#define __SPACEG_LUASPRITEENTITY__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <slua/Bind.hpp>

#include "LuaInterface.hpp"
#include "../base/GraphicEntity.hpp"
#include "../render/SfmlSprite.hpp"


namespace spaceg {
	
/**
* Lua Bindings für Sprite Entity
*/	
class LuaSpriteEntity : public slua::LuaObject, public spaceg::GraphicEntity
{
private:
	SfmlSprite sprite_;
	//shader
	sf::Shader shader_;
	//render states
    sf::RenderStates states_;	
    
    //disable/enable shader
    
    //save Application Reference here
public:

	LuaSpriteEntity();
	virtual ~LuaSpriteEntity();

	//filename
	int loadTexture(slua::Context& ctx);
	
	//position
	//texturePosition
	int setColor(slua::Context& ctx);
	int setPosition(slua::Context& ctx);
	int setSize(slua::Context& ctx);
	int setTextureRect(slua::Context& ctx);
	
	//load shader
	int loadFragmentShader(slua::Context& ctx);
	int loadVertexShader(slua::Context& ctx);
	
	//shaderArguments?
	
	//move texture
	int moveTextureRect(slua::Context& ctx); //moveTextureRect
	
	virtual int render(slua::Context& ctx);
	
	//Binding Information
	static const slua::BindStatus<LuaSpriteEntity> bindStatus;
	
	//LuaInterface
	static const LuaBindInterface<LuaSpriteEntity> luaInterface;
};




} //end namespace spaceg


#endif

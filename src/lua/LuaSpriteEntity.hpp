



#pragma once
#ifndef __SPACEG_LUASPRITEENTITY__
#define __SPACEG_LUASPRITEENTITY__

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Shader.hpp>

#include <slua/Bind.hpp>

#include "../base/GraphicEntity.hpp"


namespace spaceg {
	
/**
* Lua Bindings für Sprite Entity
*/	
class LuaSpriteEntity : public slua::LuaObject //public spaceg::GraphicEntity,
{
private:
    //sprite
	sf::Sprite sprite_;
	//shader
	sf::Shader shader_;
	//render states
    sf::RenderStates states_;	
    
    //disable/enable shader
public:

	LuaSpriteEntity();
	virtual ~LuaSpriteEntity();

	//filename
	int loadTexture(slua::Context& ctx);
	
	//load shader
	int loadFragmentShader(slua::Context& ctx);
	int loadVertexShader(slua::Context& ctx);
	
	//shaderArguments?
	
	//move texture
	
	virtual int render(slua::Context& ctx);
	
	//Binding Information
	static const slua::BindStatus<LuaSpriteEntity> bindStatus;
};




} //end namespace spaceg


#endif

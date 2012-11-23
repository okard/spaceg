



#pragma once
#ifndef __SPACEG_LUASPRITEENTITY__
#define __SPACEG_LUASPRITEENTITY__

#include <SFML/Graphics/Sprite.hpp>

#include <slua/Bind.hpp>

#include "../render/SfmlEntity.hpp"


namespace spaceg {
	
/**
* Lua Bindings für Sprite Entity
*/	
class LuaSpriteEntity : public SfmlEntity, public slua::LuaObject
{
private:

	sf::Sprite sprite_;
	
public:

	//filename
	void loadTexture();
	
	//load shader
	void loadShader();
	
	//shaderArguments?
	
	
	virtual void render();
	
};




} //end namespace spaceg


#endif

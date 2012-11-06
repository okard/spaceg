

#pragma once
#ifndef __SPACEG_SPRITEENTITY__
#define __SPACEG_SPRITEENTITY__

#include <SFML/Graphics/Sprite.hpp>

#include "GraphicEntity.h"
#include "../ResourceManager.h"

namespace spaceg {
	
/**
* Basic Sprite entity
*/
class SpriteEntity : public GraphicEntity
{
private:

	sfml::Sprite sprite_;

public:
	
	//load texture
	//set color
	//set rotation
	

};
	
	
} //end namespace spaceg

#endif

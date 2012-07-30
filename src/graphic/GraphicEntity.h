
#pragma once
#ifndef __SPACEG_GRAPHICENTITY__
#define __SPACEG_GRAPHICENTITY__

#include <SFML/Graphics/Drawable.hpp>

#include "../game/Entity.h"

namespace spaceg {

/**
* Graphic Entity to render
*/
class GraphicEntity : public Entity, public sf::Drawable 
{
private:
    
    //has sprite?
    //position absolute/relative?
    
    //GraphicEntity Type for ordering
    
    //graphic layer
    short layerId_;
    
protected:
    //access to render target
    //sf::RenderTarget* target_;
    
public:
    GraphicEntity() : 
        Entity(TypeGraphic)
    {   
    }
    
    virtual ~GraphicEntity()
    {
    }
    
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const
    {
    }
};

}

#endif // __SPACEG_GRAPHICENTITY__
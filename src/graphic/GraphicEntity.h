
#pragma once
#ifndef __SPACEG_GRAPHICENTITY__
#define __SPACEG_GRAPHICENTITY__

#include <SFML/Drawable.hpp>

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
    
public:
    GraphicEntity();
    virtual ~GraphicEntity();
    
    virtual void draw (RenderTarget &target, RenderStates states) const;
};

}

#endif // __SPACEG_GRAPHICENTITY__
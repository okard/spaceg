

#pragma once
#ifndef __SPACEG_SHIPGRAPHIC__
#define __SPACEG_SHIPGRAPHIC__

#include "GraphicEntity.h"

#include <SFML/Graphics/Sprite.hpp>


namespace spaceg {

class Ship;
    
/**
* Graphical representation of a ship
*/ 
class ShipGraphic : public GraphicEntity
{
private:
    
    //reference to ship
    Ship* const ship_;
    
    //texture
    sf::Sprite shipSprite_;
    
    //model
    
public:
    
    ShipGraphic(Ship* const ship);
    
    virtual ~ShipGraphic();
    
    virtual void update(long timeElapsed);
    
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
    
    //get ship
    
    //set texture
    
    //positioning
       
};
      
} //end namespace spaceg

#endif // __SPACEG_SHIPGRAPHIC__

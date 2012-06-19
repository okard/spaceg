

#pragma once
#ifndef __SPACEG_SHIPGRAPHIC__
#define __SPACEG_SHIPGRAPHIC__

#include "GraphicEntity.h"


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
    //model
    
public:
    
    ShipGraphic(Ship* const ship);
    
    virtual ~ShipGraphic();

    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
       
};
      
} //end namespace spaceg

#endif // __SPACEG_SHIPGRAPHIC__

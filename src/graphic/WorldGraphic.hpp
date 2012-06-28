
#pragma once
#ifndef __SPACEG_WORLDGRAPHIC__
#define __SPACEG_WORLDGRAPHIC__

#include <SFML/Graphics/Vertex.hpp>

#include "GraphicEntity.h"

namespace sf { class Texture; }


namespace spaceg {
    
class World;
    
/**
* World Graphic
*/
class WorldGraphic : public GraphicEntity
{
private:
    
    //world
    World* const world_;
    
    //position
    float x_, y_;
    
    //starfield texture
    sf::Texture* tex_;
    
    //sf::Vertex für quads
    sf::Vertex vertices_[4];
    
    //Hold Nebula Graphics and so on
    
public:
    /**
    * Create graphical representation of a world
    */
    WorldGraphic(World* const world);
    
    /**
    * Destroy graphical world
    */
    virtual ~WorldGraphic();
    
    /**
    * Update entity with current elapsed time
    */
    virtual void update(long timeElapsed);
    
    /**
    * Draw world
    */
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
     
    
    //internal speed factor?
    //void move(float offsetX, float offsetY);

};
    
    
} //end namespace spaceg




#endif // __SPACEG_WORLDGRAPHIC__

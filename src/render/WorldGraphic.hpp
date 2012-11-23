
#pragma once
#ifndef __SPACEG_WORLDGRAPHIC__
#define __SPACEG_WORLDGRAPHIC__

#include <SFML/Graphics/Vertex.hpp>

#include "SfmlEntity.hpp"
#include "NebulaGraphic.h"


namespace sf { class Texture; }


namespace spaceg {
    
class World;
    
/**
* World Graphic
*/
class WorldGraphic : public SfmlEntity
{
private:
    
    //world
    World* const world_;
    
    //position -> 4 points?
    float x_, y_;
    
    //starfield texture
    sf::Texture* spacefieldTex_;
    
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
     
    
    
    void setSpaceFieldTexture(sf::Texture* tex);
    
    
    
    //internal speed factor?
    //void move(float offsetX, float offsetY);

};
    
    
} //end namespace spaceg




#endif // __SPACEG_WORLDGRAPHIC__

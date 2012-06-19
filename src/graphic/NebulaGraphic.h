

#pragma once
#ifndef __SPACEG_NEBULAENTITY__
#define __SPACEG_NEBULAENTITY__

#include "../Types.h"
#include "GraphicEntity.h"


namespace spaceg {


/**
* Class to render nebula
*/
class NebulaGraphic : public GraphicEntity
{
private:
    
    //layer of nebula
    ubyte layerCount_;
    
    //color:
    
    
    //sf::Vertex quads
    //custom shader
    
public:
    
    virtual ~NebulaGraphic();
    
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
    
    
};

}

#endif //  __SPACEG_GRAPHICENTITY__
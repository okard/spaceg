

#pragma once
#ifndef __SPACEG_NEBULAGRAPHIC__
#define __SPACEG_NEBULAGRAPHIC__

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
    
    //base texture
    
    
    //sf::Vertex quads
    //custom shader
    
    
    //see for reference: https://www.youtube.com/watch?v=CaTI2d0tQME
    
public:
    
    virtual ~NebulaGraphic();
    
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
    
    
};

}

#endif //  __SPACEG_NEBULAGRAPHIC__
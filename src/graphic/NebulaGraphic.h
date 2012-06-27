

#pragma once
#ifndef __SPACEG_NEBULAGRAPHIC__
#define __SPACEG_NEBULAGRAPHIC__

#include <vector>

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Color.hpp>

#include "../Types.h"
#include "GraphicEntity.h"

//Forward Declarations
namespace sf { class Texture; }


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
    sf::Color color_;
    
    //base texture (sprite?)
    sf::Texture* texture_;
    
    //vertexes
    std::vector<sf::Vertex> vertexes_;
    
    
    //custom shader
    
    
    //see for reference: https://www.youtube.com/watch?v=CaTI2d0tQME
    
public:
    /**
    * Constructor
    */
    NebulaGraphic();
    
    /**
    * Constructor
    */
    NebulaGraphic(sf::Texture* tex);
    
    /**
    * Destructor
    */
    virtual ~NebulaGraphic();
    
    /**
    * Create random settings
    * At the moment only for test purposes 
    */
    void random();
    
    /**
    * Set texture
    */
    void setTexture(sf::Texture* tex);
    
    /**
    * SFML Drawable Interface
    * \sa { http://www.sfml-dev.org/documentation/2.0/classsf_1_1Drawable.php }
    */
    virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;
};

}

#endif //  __SPACEG_NEBULAGRAPHIC__
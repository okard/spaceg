

#include "NebulaGraphic.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

using namespace spaceg;


NebulaGraphic::~NebulaGraphic()
{
    
}

void NebulaGraphic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(vertexes_.size() <= 0)
        return;
    
    //prepare shader
    
    //render one texture multiple times with different colors
    
    
    target.draw(&vertexes_[0], vertexes_.size(), sf::Quads, states);
}
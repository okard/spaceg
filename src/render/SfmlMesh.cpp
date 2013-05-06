

#include "SfmlMesh.hpp"

using namespace spaceg;


SfmlMesh::SfmlMesh()
{
    
}

SfmlMesh::~SfmlMesh()
{
    
}
 
void SfmlMesh::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.pushGLStates();    
    
    target.popGLStates();
}



#include "SfmlMesh.h"


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
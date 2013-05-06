
#pragma once
#ifndef __SPACEG_SFMLMESH__
#define __SPACEG_SFMLMESH__

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace spaceg {

/**
* Extended Sfml Shape
*/
class SfmlMesh : public sf::Drawable
{
private:
    
    sf::Shader shader;
    //vbo vertexes
    //vbo elements
    
public:
    SfmlMesh();
    virtual ~SfmlMesh();
    
    //vertex format?
    //shader
    //set translate matrix for shader from RenderStates
    
    //add sf:.Vertex + Indices
    
    //add a x binary loader
    
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;   
};



} //end namespace spaceg

#endif //__SPACEG_SFMLMESH__

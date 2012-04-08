
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
    //vbo
    //vbo
    
    
public:
    
    //vertex format?
    //shader
    
    virtual ~SfmlMesh();
    
    void draw (sf::RenderTarget &target, sf::RenderStates states) const;   
};



} //end namespace spaceg

#endif //__SPACEG_SFMLMESH__
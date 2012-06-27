

#include "NebulaGraphic.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../game/Random.hpp"

#include <iostream>

using namespace spaceg;

/**
* Constructor
*/
NebulaGraphic::NebulaGraphic()
    : texture_(nullptr), layerCount_(1)
{
    
}

/**
* Constructor
*/
NebulaGraphic::NebulaGraphic(sf::Texture* tex)
     : texture_(tex), layerCount_(1)
{
}


NebulaGraphic::~NebulaGraphic()
{
    
}

//create random settings
void NebulaGraphic::random()
{
    vertexes_.clear();
    
    MersenneTwister rand(0x896b1f30);
    
    
    //TODO use a seed to get the values
    
    //pick color
        
    sf::Color c = sf::Color(rand.random(0,255), rand.random(0,255), rand.random(0,255), 255);
    
    //pick random count of layer
    layerCount_ = 4;
    
    auto texSize = texture_->getSize();
    
    //create sf:Vertex
    //set color and texture coord sf::Vertex -> layerCount * 4
    for(int i=0; i < layerCount_; i++)
    {
        int quadSize = 500;
                
        sf::Transform proj;
        //proj.rotate(20*i);
        proj.rotate(45*i, quadSize/2, quadSize/2);
        proj.translate(rand.random(35,60), rand.random(35,60));
        //translate in random direction?
        
        //Vector2f rotation.transformPoint (const Vector2f &point) const 
        //+ minimal translation? .translate(float, float);
    
        //set right coords
        //color transparncy for each layer?

        //Vertex (const Vector2f &thePosition, const Color &theColor, const Vector2f &theTexCoords)
        vertexes_.push_back(sf::Vertex(proj.transformPoint(sf::Vector2f(0, 0)), c, sf::Vector2f(0, 0)));
        vertexes_.push_back(sf::Vertex(proj.transformPoint(sf::Vector2f(0, quadSize)), c, sf::Vector2f(0, 1)));
        vertexes_.push_back(sf::Vertex(proj.transformPoint(sf::Vector2f(quadSize, quadSize)), c, sf::Vector2f(1, 1)));
        vertexes_.push_back(sf::Vertex(proj.transformPoint(sf::Vector2f(quadSize, 0)), c, sf::Vector2f(1, 0)));
    } 
}

    
/**
* Set texture
*/
void NebulaGraphic::setTexture(sf::Texture* tex)
{
    if(tex)
        texture_ = tex;
}

void NebulaGraphic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if(vertexes_.size() <= 0)
        return;
    
    //prepare shader
    
    //render one texture multiple times with different colors
    if(texture_)
        texture_->bind();
    
    //std::cout << "Render: " << vertexes_.size() << std::endl;
    target.draw(&vertexes_[0], vertexes_.size(), sf::Quads, states);
}


#include "NebulaGraphic.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../utils/Random.hpp"

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
    
    MersenneTwister rand;
    unsigned int seed = rand.random();
    
    std::cout << "Seed: " << seed << std::endl;
    rand.seed(seed);
    
    //green: 2807516958
    //blue: 251307725
    //violet: 3693675364, 1041013430
    //136749304
    
    //TODO use a seed to get the values
    
    //pick color
        
    sf::Color c = sf::Color(rand.random(100,255), rand.random(100,255), rand.random(100,255), 255);
    
    //pick random count of layer
    layerCount_ = rand.random(2,8);
    
    //create sf:Vertex
    //set color and texture coord sf::Vertex -> layerCount * 4
    for(int i=0; i < layerCount_; i++)
    {
        int quadSize = 400;
                
        sf::Transform proj;
        proj.rotate(rand.random(30,50)*i, quadSize/2, quadSize/2);
        proj.translate(rand.random(35,60), rand.random(35,60));

        //color transparency for each layer?

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
    
    states.transform.translate(1,1);
    
    //prepare shader
    
    //render one texture multiple times with different colors
    if(texture_)
        texture_->bind();
    
    //std::cout << "Render: " << vertexes_.size() << std::endl;
    target.draw(&vertexes_[0], vertexes_.size(), sf::Quads, states);
}
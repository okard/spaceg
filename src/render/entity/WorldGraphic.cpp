
#include "WorldGraphic.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>

using namespace spaceg;




WorldGraphic::WorldGraphic(World* const world)
    : world_(world),
      spacefieldTex_(nullptr),
      x_(0), y_(0)
{
    vertices_[0].position = sf::Vector2f(0, 0);
    vertices_[1].position = sf::Vector2f(0, 1);
    vertices_[2].position = sf::Vector2f(1, 1);
    vertices_[3].position = sf::Vector2f(1, 0);
}

WorldGraphic::~WorldGraphic()
{
}

/**
* Update entity with current elapsed time
*/
void WorldGraphic::update(long timeElapsed)
{
    //use right texture tiling factor?
    //Shrink
    
    // 5er scope in 10 range? math
    
    float fac = 3;
    
    vertices_[0].texCoords = sf::Vector2f(0, 0);
    vertices_[1].texCoords = sf::Vector2f(0, fac);
    vertices_[2].texCoords = sf::Vector2f(fac, fac);
    vertices_[3].texCoords = sf::Vector2f(fac, 0);
    
    //complete world size relation to position with maximum tiling mapping
    // n tiles for the current screen (depend also on zoom level?)
    // world is x,y
    // position in world
}
    
    
void WorldGraphic::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
    //draw world background
    
    //pay attention for zoom level?
    
    //scaling of background quad
    auto v = target.getView();
    auto vp = v.getViewport();
    auto s = v.getSize();
    
    states.transform.translate(-vp.left, -vp.top);
    states.transform.scale(s.x, s.y);
    
    //render spacefield
    if(spacefieldTex_)
		sf::Texture::bind(spacefieldTex_);
        
    target.draw(&vertices_[0], 4, sf::Quads, states);
    
    //reset states?
    //draw rest of world, planets nebula
 
}


void WorldGraphic::setSpaceFieldTexture(sf::Texture* tex)
{
    if(tex)
    {
        spacefieldTex_ = tex;
        spacefieldTex_->setRepeated(true); 
    }
}
     

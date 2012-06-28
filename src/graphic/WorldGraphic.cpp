
#include "WorldGraphic.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Graphics/Texture.hpp>


using namespace spaceg;




WorldGraphic::WorldGraphic(World* const world)
    : world_(world)
{
}

WorldGraphic::~WorldGraphic()
{
}

/**
* Update entity with current elapsed time
*/
void WorldGraphic::update(long timeElapsed)
{
    //set position for vertices
    auto vp = target_->getView().getViewport();
    
    vertices_[0].position = sf::Vector2f(vp.left, vp.top);
    vertices_[1].position = sf::Vector2f(0, vp.top+vp.width);
    vertices_[2].position = sf::Vector2f(vp.left+vp.height, vp.top+vp.width);
    vertices_[3].position = sf::Vector2f(vp.left+vp.height, 0);
}
    
    
void WorldGraphic::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
    //use the states.transform for right drawing?
    
    //create texture mapping
    
    //const FloatRect& sf::View::getViewport    (       )
    
    //use target size a view to set quad coords
             
    //current view of starfield
    
    //Create a quad
    //using reapeted texture
    //move tex coords
    
    //center point is 0.5f, 0.5f
    //use a position to set the tex coords
    
    //const Vector2f &  getCenter () const
    //Get the center of the view.
    //const Vector2f &    getSize () const 
}
     
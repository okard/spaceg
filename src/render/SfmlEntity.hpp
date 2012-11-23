
#pragma once
#ifndef __SPACEG_SFMLENTITY__
#define __SPACEG_SFMLENTITY__

#include <SFML/Graphics/Drawable.hpp>

#include "../base/GraphicEntity.hpp"

namespace spaceg {

/**
* Graphic Entity to render
*/
class SfmlEntity : public GraphicEntity 
{
private:
    
    //render target (shared_ptr)
    sf::RenderTarget* target;
    //render states
    sf::RenderStates states;
    
public:
	/**
	* Creates a new SfmlEntity
	*/
    SfmlEntity();
    
    /**
    * Create new SfmlEntity
    */
    SfmlEntity(sf::RenderTarget& target, sf::RenderStates states);
    
    /**
    * Destructor
    */
    virtual ~SfmlEntity();
    
    /**
    * Render the entity to attached render target
    */
    virtual void render();
};

}

#endif // __SPACEG_SFMLENTITY__

#pragma once
#ifndef __SPACEG_GRAPHICENTITY__
#define __SPACEG_GRAPHICENTITY__

#include "Entity.hpp"

namespace spaceg {

//TODO inherit from game object?  
//TODO Entity Lifecycle, Events: create, destroy, active, etc  
    
/**
* Basic Graphic Entity
*/
class GraphicEntity : public Entity
{
private:

	
public:
	/**
	* Render Signal
	*/
	cul::signal<> OnRender;
	
	/**
    * Add a child entity
    */
    void addEntity(std::shared_ptr<GraphicEntity> entity);
    
    /**
    * Remove child entity
    */
    void removeEntity(std::shared_ptr<GraphicEntity> entity);

	/**
	* Render Node
	*/
	virtual void render();
};



} //end namespace spaceg

#endif // __SPACEG_GRAPHICENTITY__

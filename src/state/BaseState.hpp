
#pragma once
#ifndef __SPACEG_GAMESTATE__
#define __SPACEG_GAMESTATE__

#include <vector>

#include "State.hpp"

/*
* SpaceG Namespace
*/
namespace spaceg {

class Application;
class Entity;
    
/**
* Basic Game State
* TODO templated for entities?
*/
class BaseState : public State
{
private:
    
    //TODO split logic, graphic entities
        // sorting of graphic entities?
        
	//TODO Quadtree implementation for storage
	//TODO Picking API
	
	//TODO Decals?
        
    //saved entities
    std::vector<Entity*> entities_;
    
    
    //application
    Application* app_;
    
public:
    /**
    * Constructor
    */
    BaseState();
    
    /**
    * Destructor
    */
    virtual ~BaseState();
    
    /**
    * Attach a game entity to this state
    */
    void attach(Entity* const entity); 
    
    /**
    * Activate state for this application;
    */
    virtual void activate(Application* const app);
    
    /**
    * Update Game State
    */
    virtual void update(long timeElapsed);
        
    /**
    * Draw current state
    */
    virtual void draw();
    
    /**
    * Clean up state
    */
    virtual void cleanup();
    
    //getApplication()
    
};
    
    
    
} //end namespace spaceg

#endif


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
* Rename to Application State
*/
class BaseState : public State
{
private:
    
    //TODO split logic, graphic entities
        // sorting of graphic entities?
        
	//TODO Quadtree implementation for storage
	//TODO Picking API
	 
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
    * Activate state for this application;
    */
    virtual void activate();
    
    /**
    * Update Game State
    */
    virtual void update(long timeElapsed);
        
    /**
    * Draw current state
    */
    virtual void draw();
    
    /**
    * Set the Application Interface
    */
    void setApplication(Application* const app);
    
    /**
    * Get Application
    */
    Application* const getApplication();
    
};
    
    
    
} //end namespace spaceg

#endif

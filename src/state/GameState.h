
#pragma once
#ifndef __SPACEG_GAMESTATE__
#define __SPACEG_GAMESTATE__

#include <vector>

#include "IState.h"

/*
* SpaceG Namespace
*/
namespace spaceg {

class Application;
class Entity;
    
/**
* Basic Game State
*/
class GameState : public IState
{
private:
    
    //TODO split logic, graphic entities
        // sorting of graphic entities?
        
    //saved entities
    std::vector<Entity*> entities_;
    
    //application
    Application* app_;
    
public:
    /**
    * Constructor
    */
    GameState();
    
    /**
    * Destructor
    */
    virtual ~GameState();
    
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
    
};
    
    
    
} //end namespace spaceg

#endif
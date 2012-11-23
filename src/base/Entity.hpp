

#pragma once
#ifndef __SPACEG_ENTITY__
#define __SPACEG_ENTITY__

#include <memory>
#include <unordered_set>

#include <culcore/Signal.hpp>

#include "Geometry.hpp"

namespace spaceg {

//TODO inherit from game object?  
//TODO Entity Lifecycle, Events: create, destroy, active, etc  
    
/**
* Basic Game Entity
*/
class Entity
{
	
private:
    //save entities
    //notice  std::hash<std::shared_ptr> exists
    std::unordered_set<std::shared_ptr<Entity>> entities_;
    
protected:
    // it is a static entity
    // means fixed position
    bool static_ = false;
    
    // the entity is active
    // entity exist and can be used
    bool active_ = true;
    
	// position
    Rectf position_;
      
public:
	//Update Event
    cul::signal<long> OnUpdate;
    
    /**
    * Default constructor
    */
    Entity();
    
    /**
    * Destructor
    */
    virtual ~Entity();
    
    /**
    * Return true if entity requires an update
    * TODO Remove
    */
    virtual bool requestUpdate() const;
    
    /**
    * Update entity with current elapsed time
    */
    virtual void update(long timeElapsed);
    
    /**
    * Add a child entity
    */
    void addEntity(std::shared_ptr<Entity> entity);
    
    /**
    * Remove child entity
    */
    void removeEntity(std::shared_ptr<Entity> entity);
    
    /**
    * Get Position of Entity
    */
    const Rectf& getPosition() const;
    
    /**
    * Is static entity
    */
    bool isStatic();
    
    /**
    * Is active
    */
    bool isActive();
    
    
};
    
} //end namespace spaceg

#endif

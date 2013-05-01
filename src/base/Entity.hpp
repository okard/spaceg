

#pragma once
#ifndef __SPACEG_ENTITY__
#define __SPACEG_ENTITY__

#include <memory>
#include <unordered_set>

#include <culcore/Signal.hpp>

#include "Geometry.hpp"

namespace spaceg {
	
class Entity;
typedef std::shared_ptr<Entity> EntityPtr;
typedef std::unordered_set<EntityPtr> EntityList;

typedef cul::signal<long> UpdateSignal;

//TODO inherit from game object?  
//TODO Entity Lifecycle
//     Events: create, destroy, active, etc  
    
/**
* Basic Game Entity
* Split to Entity and Entity2D
*/
class Entity //: public std::enable_shared_from_this<Entity> ?
{
	
private:
    //save entities
    EntityList entities_;
    
protected:
    // it is a static entity
    // it doesn't change
    bool static_ = false;
    
    // the entity is active
    // entity exist and can be used
    bool active_ = true;
    
    //logic entities? like quadtree and so on for optimized container rendering?
    //-> QuadTreeSceneEntity -> PlayerLogicEntity -> PlayerSprite
    
	// position
    Rectf position_;
      
public:
	//Update Event
    UpdateSignal OnUpdate;
    
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
    void addEntity(EntityPtr entity);
    
    /**
    * Remove child entity
    */
    void removeEntity(EntityPtr entity);
    
    /**
    * Get Position of Entity
    */
    inline const Rectf& getPosition() const { return position_; }
    
    /**
    * Is static entity
    */
    inline bool isStatic() const { return static_; }
    
    /**
    * Is active
    */
    inline bool isActive() const { return active_; }  
};
    
} //end namespace spaceg

#endif

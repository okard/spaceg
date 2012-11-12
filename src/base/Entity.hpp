

#pragma once
#ifndef __SPACEG_ENTITY__
#define __SPACEG_ENTITY__

#include "Geometry.hpp"

namespace spaceg {

//TODO inherit from game object?  
//TODO Entity Lifecycle, Events: create, destroy, active, etc  
    
/**
* Basic Game Entity
*/
class Entity
{
protected:
    // it is a static entity
    // means fixed position
    bool static_ = false;
    
    // the entity is active
    // entity exist and can be used
    bool active_ = true;
    
    //position
    Rectf position_;
    
public:
    
    /**
    * Default constructor
    */
    Entity();
    
    /**
    * Return true if entity requires an update
    */
    virtual bool requestUpdate() const;
    
    /**
    * Update entity with current elapsed time
    */
    virtual void update(long timeElapsed);
    
    
    //position
    // const Rectf& getPosition() const;
    
};
    
} //end namespace spaceg

#endif

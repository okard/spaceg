

#pragma once
#ifndef __SPACEG_ENTITY__
#define __SPACEG_ENTITY__

#include "Geometry.hpp"

namespace spaceg {

//TODO inherit from game object?    
    
/**
* Basic Game Entity
*/
class Entity
{
protected:
    // it is a static entity
    bool static_ = false;
    
    // the entity is active
    bool active_ = true;
    
    //position
    Rectf position;
    
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
    
};
    
} //end namespace spaceg

#endif

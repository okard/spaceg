

#pragma once
#ifndef __SPACEG_ENTITY__
#define __SPACEG_ENTITY__

namespace spaceg {
    
/**
* Basic Game Entity
*/
class Entity
{
public:
    //TODO Rename to category
    enum EntityType
    {
        TypeLogic,
        TypeGraphic,
        TypeCustom
    };
    
protected:
    // it is a static entity
    bool static_;
    
    // the entity is active
    bool active_;
    
    // entity type
    EntityType entityType_;
    
public:
    
    /**
    * Default constructor
    */
    Entity();
    
    /**
    * Entity with given type
    */
    Entity(EntityType type);
    
    /**
    * Return true if entity requires an update
    */
    virtual bool requestUpdate();
    
    /**
    * Update entity with current elapsed time
    */
    virtual void update(long timeElapsed);
    
    /**
    * Get entity type
    */
    EntityType getType();
    
};




//GraphicEntity has a Sprite?
    
} //end namespace spaceg

#endif
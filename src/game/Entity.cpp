
#include "Entity.h"


using namespace spaceg;

/**
* Default constructor
*/
Entity::Entity()
    : entityType_(TypeLogic)
{
}

/**
* Entity with given type
*/
Entity::Entity(EntityType type)
    : entityType_(type)
{
}


/// Request update when not static and active
bool Entity::requestUpdate()
{
    return !static_ && active_;
}

///default implementation nothing to do here
void Entity::update(long timeElapsed)
{
}

/**
* Get entity type
*/
Entity::EntityType Entity::getType()
{
    return entityType_;
}

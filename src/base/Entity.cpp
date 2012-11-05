
#include "Entity.hpp"


using namespace spaceg;

/**
* Default constructor
*/
Entity::Entity()
{
}


/// Request update when not static and active
bool Entity::requestUpdate() const
{
    return !static_ && active_;
}

///default implementation nothing to do here
void Entity::update(long timeElapsed)
{
}


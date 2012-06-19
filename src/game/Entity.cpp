
#include "Entity.h"


using namespace spaceg;


/// Request update when not static and active
bool Entity::requestUpdate()
{
    return !static_ && active_;
}

///default implementation nothing to do here
void Entity::update(long timeElapsed)
{
}


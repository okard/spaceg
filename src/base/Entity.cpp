
#include "Entity.hpp"


using namespace spaceg;

/**
* Default constructor
*/
Entity::Entity()
{
}

/**
* Destructor
*/
Entity::~Entity()
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
	if(isActive())
		OnUpdate(timeElapsed);
}

/// Add the child entity to internal list
void Entity::addEntity(EntityPtr entity)
{
	if(!entity)
		return;
		
	//TODO Register Events here
	OnUpdate.connect(entity.get(), &Entity::update);

	entities_.insert(entity);
}

/**
* Remove child entity
*/
void Entity::removeEntity(std::shared_ptr<Entity> entity)
{
	if(!entity)
		return;
	
	OnUpdate.disconnect(entity.get(), &Entity::update);
	
	entities_.erase(entity);
}
    

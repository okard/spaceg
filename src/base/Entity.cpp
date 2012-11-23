
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
void Entity::addEntity(std::shared_ptr<Entity> entity)
{
	if(!entity)
		return;
		
	//TODO Register Events here
	OnUpdate.connect<Entity, &Entity::update>(entity.get());

	entities_.insert(entity);
}

/**
* Remove child entity
*/
void Entity::removeEntity(std::shared_ptr<Entity> entity)
{
	if(!entity)
		return;
	
	entities_.erase(entity);
}
    

/**
* Get Position of Entity
*/
const Rectf& Entity::getPosition() const
{
	return position_;
}

/**
* Is static entity
*/
bool Entity::isStatic()
{
	return static_;
}

/**
* Is active
*/
bool Entity::isActive()
{
	return active_;
}

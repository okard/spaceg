

#include "GraphicEntity.hpp"

using namespace spaceg;

/**
* Add a child entity
*/
void GraphicEntity::addEntity(std::shared_ptr<GraphicEntity> entity)
{
	if(entity)
	{
		OnRender.connect(entity.get(), &GraphicEntity::render);
		Entity::addEntity(entity);
	}
}

/**
* Remove child entity
*/
void GraphicEntity::removeEntity(std::shared_ptr<GraphicEntity> entity)
{
	Entity::removeEntity(entity);
}

/**
* Render Node
*/
void GraphicEntity::render()
{
	//call sub nodes
	if(isActive())
		OnRender();
		
}
	

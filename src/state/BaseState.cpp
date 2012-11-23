
#include "BaseState.hpp"

//Todo Remove SDML/liBRocket Dependencies


#include <SFML/Graphics/Sprite.hpp>
#include <Rocket/Core/ElementDocument.h>

#include "../Application.h"
#include "../base/Entity.hpp"
#include "../render/SfmlEntity.hpp"

#include <iostream>


using namespace spaceg;

/**
* Constructor
*/
BaseState::BaseState()
    : app_(nullptr)
{
    entities_.reserve(10);
}
    
    
/**
* Destructor
*/
BaseState::~BaseState()
{
}

/**
* Attach a game entity to this state
*/
void BaseState::attach(Entity* const entity)
{
    entities_.push_back(entity);
}


/**
* Activate state for this application;
*/
void BaseState::activate()
{
}

/**
* Update Game State
*/
void BaseState::update(long timeElapsed)
{
    //keyboard/mouse input?
    
    //update logic part of entities
    for(Entity* e: entities_)
    {
        if(e->requestUpdate())
            e->update(timeElapsed);
    }
}
    
/**
* Draw current state
*/
void BaseState::draw()
{
    if(app_ == nullptr)
        return;
    
    for(Entity* e: entities_)
    {
		/*
        //Order graphic entities for faster rendering
        if(e->getType() == Entity::TypeGraphic)
        {
            const GraphicEntity& ge = static_cast<GraphicEntity&>(*e);
            
            //rende GraphicEntity which is a sf::Drawable over Application interface
            
            app_->getRenderTarget()->draw(ge);
        }
        */
    }
}

/**
* Clean up state
*/
void BaseState::cleanup()
{
    entities_.clear();
}

/**
* Set the Application Interface
*/
void BaseState::setApplication(Application* const app)
{
	app_ = app;
}

/**
* Get Application
*/
Application* const BaseState::getApplication()
{
	return app_;
}

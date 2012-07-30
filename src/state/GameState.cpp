
#include "GameState.h"


#include <SFML/Graphics/Sprite.hpp>
#include <Rocket/Core/ElementDocument.h>

#include "../Application.h"
#include "../game/Entity.h"
#include "../graphic/GraphicEntity.h"

#include <iostream>


using namespace spaceg;

/**
* Constructor
*/
GameState::GameState()
    : app_(nullptr)
{
    entities_.reserve(10);
}
    
    
/**
* Destructor
*/
GameState::~GameState()
{
}

/**
* Attach a game entity to this state
*/
void GameState::attach(Entity* const entity)
{
    entities_.push_back(entity);
}


/**
* Activate state for this application;
*/
void GameState::activate(Application* const app)
{
    app_ = app;
}

/**
* Update Game State
*/
void GameState::update(long timeElapsed)
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
void GameState::draw()
{
    if(app_ == nullptr)
        return;
    
    for(Entity* e: entities_)
    {
        //Order graphic entities for faster rendering
        if(e->getType() == Entity::TypeGraphic)
        {
            const GraphicEntity& ge = static_cast<GraphicEntity&>(*e);
            
            //rende GraphicEntity which is a sf::Drawable over Application interface
            
            app_->getRenderTarget()->draw(ge);
        }
    }
}

/**
* Clean up state
*/
void GameState::cleanup()
{
    entities_.clear();
}
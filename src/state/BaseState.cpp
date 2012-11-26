
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
}
    
    
/**
* Destructor
*/
BaseState::~BaseState()
{
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
    
    
}
    
/**
* Draw current state
*/
void BaseState::draw()
{
    if(app_ == nullptr)
        return;
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

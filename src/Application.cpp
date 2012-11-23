
#include "Application.h"

#include <GL/glew.h>

#include <SFML/Graphics.hpp>

#include "GameException.hpp"
#include "ui/RenderInterface.h"
#include "ui/SfmlUtils.h"

#include "state/State.hpp"
#include "state/BaseState.hpp"

//debug
#include <iostream>


using namespace spaceg;

/*
* Create Application
*/
Application::Application()
    : window_(sf::VideoMode(1024, 768), "SpaceG", sf::Style::Titlebar | sf::Style::Close ),
      currentState_(nullptr)
{
	//Handle the view seperate from rendertexture and window 
	
    //setting up sfml render stuff
    window_.setFramerateLimit(60);
    auto size = window_.getSize();
    renderTexture_.create(size.x, size.y);
    view_ = renderTexture_.getView();
    renderTexture_.setView(view_);
    
    //glew init
    glewInit();
    
    //GUI Init
    //Getting directly rendered to window not to render texture
    uiRenderInterface_ = new RenderInterface(&window_);
    Rocket::Core::SetRenderInterface(uiRenderInterface_);
    Rocket::Core::SetSystemInterface(&uiSysInterface_);
    Rocket::Core::Initialise();
    
    uiCtx_ = Rocket::Core::CreateContext("default", Rocket::Core::Vector2i(size.x, size.y));
    
    //Load Fonts
    Rocket::Core::FontDatabase::LoadFontFace("data/font/LinLibertine_Rah.ttf", "Libertine", Rocket::Core::Font::STYLE_NORMAL, Rocket::Core::Font::WEIGHT_NORMAL);
    
    //test

    Rocket::Core::ElementDocument* document = uiCtx_->LoadDocument("data/ui_test.rml");
    if (document != NULL)
        document->Show();
    
}

Application::~Application()
{
    uiCtx_->RemoveReference();
    delete uiRenderInterface_;
}

void Application::run()
{
     //TODO Expose loop to run out of class
    
     // Start the game loop
     while (window_.isOpen())
     {
        // Process events
        sf::Event event;
        while (window_.pollEvent(event))
           handleEvent(event);
        
        update();
        render();
     }  
}

void Application::handleEvent(const sf::Event& event)
{
	//TODO ui fetch all events only
	
		 
	//1. handleEventApp
	switch(event.type)
	{
		case sf::Event::Resized:
			//resize render texture
			//window_.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
			break;
		
		// Close window : exit
		case sf::Event::Closed:
			window_.close();
			//shutdown application?
			break;
		
	}
     
	//2. handleEventUi
	handleEventUi(event);
	 
	//3. handleEventSignals
	
}

///Ui Event Handling
void Application::handleEventUi(const sf::Event& event)
{
	//TODO switch case
	
	sf::Vector2f coord; 
	
	switch(event.type)
	{
		case sf::Event::Resized: 
			coord = window_.convertCoords (sf::Vector2i(event.size.width, event.size.height)); 
			uiCtx_->SetDimensions(Rocket::Core::Vector2i(coord.x, coord.y));
			//uiCtx_->Update();
			break;
		
		case sf::Event::MouseMoved: 
			uiCtx_->ProcessMouseMove(event.mouseMove.x, event.mouseMove.y, getKeyModifier());
			break;
		case sf::Event::MouseButtonPressed:
			uiCtx_->ProcessMouseButtonDown(mouseButtonConvert(event.mouseButton.button), getKeyModifier());
			break;
		case sf::Event::MouseButtonReleased: 
			uiCtx_->ProcessMouseButtonUp(mouseButtonConvert(event.mouseButton.button), getKeyModifier());
			break;
		case sf::Event::MouseWheelMoved:
			uiCtx_->ProcessMouseWheel(event.mouseWheel.delta, getKeyModifier()); 
			break;
		case sf::Event::KeyPressed:
			uiCtx_->ProcessKeyDown(keyConvert(event.key.code), getKeyModifier());
			break;
		case sf::Event::KeyReleased:
			uiCtx_->ProcessKeyUp(keyConvert(event.key.code), getKeyModifier());
			break;
	}
	  
	// Sends a single character of text as text input into this context.
    //void ProcessTextInput(Rocket::Core::word character);
    // Sends a string of text as text input into this context.
    //void ProcessTextInput(const Rocket::Core::String& string);
}
    
    
/// Update the current game state 
void Application::update()
{
    const sf::Time elapsedTime = clock_.restart();
    
    if(currentState_)
        currentState_->update(elapsedTime.asMilliseconds());
    
    uiCtx_->Update();      
}

/// Render all the stuff
void Application::render()
{
    // Clear the whole texture with red color
    renderTexture_.clear(sf::Color::Black);
    renderTexture_.setView(view_);

	// Game state handling:
	
    // Draw stuff to the texture
    if(currentState_)
        currentState_->draw();

    // We're done drawing to the texture
    renderTexture_.display();
    
    // Clear screen
    window_.clear();
        
    //Draw Render Texture
    renderSprite_.setTexture(renderTexture_.getTexture());
    window_.draw(renderSprite_);
    //TODO Post Effects Fragment shader here please 
    //Hook posteffects together with state?
    
    
    
    //Render the ui as overlay
    uiRenderInterface_->startRender();
    uiCtx_->Render();
    uiRenderInterface_->finishRender();

    // Update the window
    window_.display();
}


void Application::switchState(State* const state)
{
    if(!state)
        return;
        
    if(currentState_)
    {
		currentState_->disable();
	}
    
    //initialize state if not yet initialized?
    
    state->activate();
    currentState_ = state;
}

sf::RenderTarget* const Application::getRenderTarget()
{
    return &renderTexture_;
}
     

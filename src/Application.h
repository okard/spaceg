

#pragma once
#ifndef __SPACEG_APPLICATION__
#define __SPACEG_APPLICATION__

#include <string>

#include <SFML/Graphics.hpp>
#include <Rocket/Core.h>

#include "ui/SystemInterface.h"



namespace spaceg {
    
class RenderInterface;
class IState;
  
/**
* Application Class
*/
class Application
{
private:
    //Logic Stuff
    sf::Clock clock_;
    
    //Render Stuff
    sf::RenderWindow window_;
    sf::RenderTexture renderTexture_; 
    sf::Sprite renderSprite_;
    sf::View view_;
    
    //UI
    SystemInterface uiSysInterface_;
    RenderInterface* uiRenderInterface_;
    Rocket::Core::Context* uiCtx_;
    
    //State Handling
    IState* currentState_;
    
public:
    /**
    * settung up application
    */
    Application();
    
    /**
    * Destruct and cleanup Application
    */
    ~Application();
    
    /**
    * Run Application
    */
    void run();
      
    /**
    * Switch State
    */
    void switchState(IState* const state);
    
    /**
    * Gets the rendering target
    */
    sf::RenderTarget * const getRenderTarget();
    
    //TODO get ui Context
    
    //TODO get view
    
private:
    //handle sfml events
    void handleEvent(const sf::Event& event);
    
    //logic update
    void update();
    
    //render to screen
    void render();
};
    
}


#endif //__SPACEG_APPLICATION__
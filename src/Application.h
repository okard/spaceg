

#pragma once
#ifndef __SPACEG_APPLICATION__
#define __SPACEG_APPLICATION__

#include <string>

#include <SFML/Graphics.hpp>
#include <Rocket/Core.h>

#include "ui/SystemInterface.h"

#include "state/State.h"
#include "state/MainMenu.h"


namespace spaceg {
    
class RenderInterface;
  
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
    
    //UI
    SystemInterface uiSysInterface_;
    RenderInterface* uiRenderInterface_;
    Rocket::Core::Context* uiCtx_;
    
    //State Handling
    State* currentState_;
    MainMenu mainMenu_;
    
public:
    Application();
    ~Application();
    
    /**
    * Run Application
    */
    void run();
      
    /**
    * Switch State
    */
    void switchState(State* const state);
    
    /**
    * Gets the rendering Texture
    */
    sf::RenderTexture* const getRenderTexture();
    
    
private:
    void handleEvent(const sf::Event& event);
    void update();
    void render();
};
    
}


#endif //__SPACEG_APPLICATION__
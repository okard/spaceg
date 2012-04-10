

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
    
    void run();
      
    void setState(State* state);
    sf::RenderTexture* const getRenderTexture();
    
    
private:
    void handleEvent(const sf::Event& event);
};
    
}


#endif //__SPACEG_APPLICATION__


#pragma once
#ifndef __SPACEG_APPLICATION__
#define __SPACEG_APPLICATION__

#include <string>

#include <SFML/Graphics.hpp>
#include <Rocket/Core.h>

#include "state/State.h"
#include "state/MainMenu.h"


namespace spaceg {
  
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
    
    //State Handling
    State* currentState_;
    MainMenu mainMenu_;
    

    
public:
    Application();
    ~Application();
    
    void run();
      
    void setState(State* state);
    sf::RenderTexture* const getRenderTexture();
};
    
}


#endif //__SPACEG_APPLICATION__
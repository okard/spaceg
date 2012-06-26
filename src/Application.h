

#pragma once
#ifndef __SPACEG_APPLICATION__
#define __SPACEG_APPLICATION__

#include <string>

#include <SFML/Graphics.hpp>
#include <Rocket/Core.h>
#include <slua/State.hpp>

#include "ui/SystemInterface.h"

#include "lua/LuaGameState.h"


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
    
    //Scripting/Lua
    slua::State luaState_;

    //State Handling
    IState* currentState_;
    
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
    void switchState(IState* const state);
    
    /**
    * Gets the rendering target
    */
    sf::RenderTarget * const getRenderTarget();
    
private:
    void handleEvent(const sf::Event& event);
    void update();
    void render();
};
    
}


#endif //__SPACEG_APPLICATION__
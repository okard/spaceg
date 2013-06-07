

#pragma once
#ifndef __SPACEG_APPLICATION__
#define __SPACEG_APPLICATION__

#include <string>

#include <SFML/Graphics.hpp>
#include <Rocket/Core.h>

#include "ui/SfmlSystemInterface.hpp"


namespace spaceg {
    
class SfmlRenderInterface;
class State;
  
/**
* Application Class
* Merging Logic, Graphic, UI Subsystem
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
    
    //UI libRocket
    SfmlSystemInterface uiSysInterface_;
    SfmlRenderInterface* uiRenderInterface_;
    Rocket::Core::Context* uiCtx_;
    
    //Input
    //SfmlInputManager
    
    //TODO use smart pointer here
    
    //State Handling
    //TODO StateStack? std::vector<std::shared_ptr<State> > StateStack;
    State* currentState_;
    
    
    //Create Signals for mouse/keyboard events  
private:
    /**
    * settung up application
    */
    Application();
    
    /**
    * Copy Ctor
    */
    Application(const Application& app){}
    
    /**
    * Destruct and cleanup Application
    */
    ~Application();
 
public:   
    /**
    * Run Application
    */
    void run();
      
    /**
    * Switch State
    */
    void switchState(State* const state);
    
    //pushState
    //popState
    
    /// Get the rendering target
    inline sf::RenderTarget* const getRenderTarget() { return &renderTexture_; }
    
    /// Get Mouse Position for Rendering Target
    sf::Vector2f getMousePositionForRenderTarget();
    
    /// The Application Instance
    static Application& getInstance();
    
private:
    ///handle sfml events
    void handleEvent(const sf::Event& event);
    
    ///Ui Event Handling
    void handleEventUi(const sf::Event& event);
    
    ///logic update
    void update();
    
    ///render to screen (draw)
    void render();
};
    
}


#endif //__SPACEG_APPLICATION__

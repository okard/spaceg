
#pragma once
#ifndef __SPACEG_MAINMENU__
#define __SPACEG_MAINMENU__

#include <SFML/Graphics.hpp>

#include "State.h"


namespace spaceg {
    
class Application;
    
/**
* Main Menu State
*/    
class MainMenu : public State
{
private:
    Application* const app_;
    
public:
    MainMenu(Application* const app);
    virtual ~MainMenu();
    
    //update
    virtual void update(long timeElapsed);
        
    //draw
    virtual void draw();
   
};


} //end namespace spaceg

#endif //__SPACEG_MAINMENU__


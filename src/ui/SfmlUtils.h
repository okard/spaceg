
#pragma once
#ifndef __SPACEG_SFMLUTILS__
#define __SPACEG_SFMLUTILS__


#include <SFML/Window/Mouse.hpp>
#include <Rocket/Core/Input.h>

/**
* SFML Mouse Button to libRocket Mouse Button
*/
inline int mouseButtonConvert(sf::Mouse::Button btn)
{
    switch(btn)
    {
        case sf::Mouse::Button::Left:
            return 0;
        case sf::Mouse::Right:
            return 1;
        case sf::Mouse::Middle:
            return 2;
        
        //XButton1    
        //XButton2    
        //ButtonCount 
            
        default: return btn;
    }
}

/**
* SFML Keyboard Key to libRocket Keyboard Key 
*/
inline Rocket::Core::Input::KeyIdentifier keyConvert(sf::Keyboard::Key k)
{
    switch(k)
    {
        case sf::Keyboard::A: return Rocket::Core::Input::KI_A;
        case sf::Keyboard::B: return Rocket::Core::Input::KI_B;
        case sf::Keyboard::C: return Rocket::Core::Input::KI_C;
        case sf::Keyboard::D: return Rocket::Core::Input::KI_D;
        case sf::Keyboard::E: return Rocket::Core::Input::KI_E;
    }
    
}

inline int getKeyModifier()
{
    int value = 0;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        value |= Rocket::Core::Input::KM_CTRL;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        value |= Rocket::Core::Input::KM_SHIFT;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        value |= Rocket::Core::Input::KM_ALT;
    /*
    KM_META = 1 << 3, // Set if at least one Meta key (the command key) is depressed.
    KM_CAPSLOCK = 1 << 4, // Set if caps lock is enabled.
    KM_NUMLOCK = 1 << 5, // Set if num lock is enabled.
    KM_SCROLLLOCK = 1 << 6 // Set if scroll lock is enabled.
    */

    return value;
}


#endif
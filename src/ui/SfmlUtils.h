
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


#endif
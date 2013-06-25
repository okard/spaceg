
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
		//case sf::Keyboard::Unkown: return Rocket::Core::Input::KI_UNKNOWN; 
        case sf::Keyboard::A: return Rocket::Core::Input::KI_A;
        case sf::Keyboard::B: return Rocket::Core::Input::KI_B;
        case sf::Keyboard::C: return Rocket::Core::Input::KI_C;
        case sf::Keyboard::D: return Rocket::Core::Input::KI_D;
        case sf::Keyboard::E: return Rocket::Core::Input::KI_E;
        case sf::Keyboard::F: return Rocket::Core::Input::KI_F;
        case sf::Keyboard::G: return Rocket::Core::Input::KI_G;
        case sf::Keyboard::H: return Rocket::Core::Input::KI_H;
        case sf::Keyboard::I: return Rocket::Core::Input::KI_I;
        case sf::Keyboard::J: return Rocket::Core::Input::KI_J;
        case sf::Keyboard::K: return Rocket::Core::Input::KI_K;
        case sf::Keyboard::L: return Rocket::Core::Input::KI_L;
        case sf::Keyboard::M: return Rocket::Core::Input::KI_M;
        case sf::Keyboard::N: return Rocket::Core::Input::KI_N;
        case sf::Keyboard::O: return Rocket::Core::Input::KI_O;
        case sf::Keyboard::P: return Rocket::Core::Input::KI_P;
        case sf::Keyboard::Q: return Rocket::Core::Input::KI_Q;
        case sf::Keyboard::R: return Rocket::Core::Input::KI_R;
        case sf::Keyboard::S: return Rocket::Core::Input::KI_S;
        case sf::Keyboard::T: return Rocket::Core::Input::KI_T;
        case sf::Keyboard::U: return Rocket::Core::Input::KI_U;
        case sf::Keyboard::V: return Rocket::Core::Input::KI_V;
        case sf::Keyboard::W: return Rocket::Core::Input::KI_W;
        case sf::Keyboard::X: return Rocket::Core::Input::KI_X;
        case sf::Keyboard::Y: return Rocket::Core::Input::KI_Y;
        case sf::Keyboard::Z: return Rocket::Core::Input::KI_Z;
        
        case sf::Keyboard::Num0: return Rocket::Core::Input::KI_0;
        case sf::Keyboard::Num1: return Rocket::Core::Input::KI_1;
        case sf::Keyboard::Num2: return Rocket::Core::Input::KI_2;
        case sf::Keyboard::Num3: return Rocket::Core::Input::KI_3;
        case sf::Keyboard::Num4: return Rocket::Core::Input::KI_4;
        case sf::Keyboard::Num5: return Rocket::Core::Input::KI_5;
        case sf::Keyboard::Num6: return Rocket::Core::Input::KI_6;
        case sf::Keyboard::Num7: return Rocket::Core::Input::KI_7;
        case sf::Keyboard::Num8: return Rocket::Core::Input::KI_8;
        case sf::Keyboard::Num9: return Rocket::Core::Input::KI_9;
        
        default: return Rocket::Core::Input::KI_UNKNOWN;
    }
    
    //KeyCount -> create lookup table Rocket::Core::Input::KeyIdentifier[sf::Keyboard::KeyCount];
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

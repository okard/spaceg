
#pragma once
#ifndef __SPACEG_SFMLINPUTMANAGER_HPP__
#define __SPACEG_SFMLINPUTMANAGER_HPP__

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace spaceg {
	
/**
* SFML Input Manager
*/
class SfmlInputManager
{
public:
	//Keyboard Keys
	bool keys[sf::Keyboard::KeyCount];
	//Mouse Buttons
	bool mbuttons[sf::Mouse::ButtonCount];
	
	
	
	///Event Hook
	void handleEvent(const sf::Event& event);
};
	
}

#endif







#pragma once
#ifndef __SPACEG_SFMLINPUTMANAGER_HPP__
#define __SPACEG_SFMLINPUTMANAGER_HPP__

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace spaceg {
	
class Application;
	
/**
* SFML Input Manager
*/
class SfmlInputManager
{
private:
	//Application& app_;
	
public:


	//Keyboard Keys
	bool keys[sf::Keyboard::KeyCount];
	//Mouse Buttons
	bool mbuttons[sf::Mouse::ButtonCount];
	
	int mouse_x;
	int mouse_y;
	int mouse_wheel;
	
	/// Get Mouse Position for Rendering Target
    sf::Vector2f getMousePositionForRenderTarget();
    
	///Event Hook
	void handleEvent(const sf::Event& event);
};
	
}

#endif






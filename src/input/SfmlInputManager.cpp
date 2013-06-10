
#include "SfmlInputManager.hpp"

using namespace spaceg;


// return the mouse position for rendering target
sf::Vector2f SfmlInputManager::getMousePositionForRenderTarget()
{
	//return renderTexture_.mapPixelToCoords(sf::Mouse::getPosition(window_), renderTexture_.getView());
}

void SfmlInputManager::handleEvent(const sf::Event& event)
{
	//saves mouse/keyboard for lua stuff
	
	switch(event.type)
	{
		case sf::Event::KeyPressed:
			keys[event.key.code] = true;
			break;
			
		case sf::Event::KeyReleased:
			keys[event.key.code] = false;
			break;
			
		case sf::Event::MouseButtonPressed:
			mbuttons[event.mouseButton.button] = true;
		
		case sf::Event::MouseButtonReleased:
			mbuttons[event.mouseButton.button] = false;
			break;
			
		case sf::Event::MouseMoved:
			mouse_x = event.mouseMove.x;
			mouse_y = event.mouseMove.y;
			break;
			
		case sf::Event::MouseWheelMoved:
			mouse_wheel = event.mouseWheel.delta; 
			break;
	}
}


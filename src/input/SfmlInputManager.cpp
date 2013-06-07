
#include "SfmlInputManager.hpp"

using namespace spaceg;


void SfmlInputManager::handleEvent(const sf::Event& event)
{
	//saves mouse/keyboard for lua stuff
	
	switch(event.type)
	{
		case  sf::Event::KeyPressed:
			keys[event.key.code] = true;
		case  sf::Event::KeyReleased:
			keys[event.key.code] = false;
	}
}


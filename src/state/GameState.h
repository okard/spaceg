
#pragma once
#ifndef __SPACEG_GAMESTATE__
#define __SPACEG_GAMESTATE__

#include "State.h"

//SFML Forward Declaration
namespace sf {
    class Sprite;
}

//LibRocket Forward Declaration
namespace Rocket {
    namespace Core {
        class ElementDocument;
    }
}

/*
* SpaceG Namespace
*/
namespace spaceg {

class Entity;
    
/**
* Basic Game State
*/
class GameState : public State
{
private:
    //GUI Documents
    //Sprites
    //Entities
    
    //sf::Sprite
    //Rocket::Core::ElementDocument*
    
public:
    

    
    void attach(Entity* const entity); 
    void attach(sf::Sprite* const sprite);
    void attach(Rocket::Core::ElementDocument* const doc);

    //cleanup
    
    //create -> LuaGameState
};
    
    
    
} //end namespace spaceg

#endif
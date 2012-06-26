


#pragma once
#ifndef __SPACEG_LUAGAMESTATE__
#define __SPACEG_LUAGAMESTATE__

#include <slua/State.hpp>

#include "../state/GameState.h"


namespace spaceg {

/**
* Lua Game States
* The class represents a game state which is controlled by a lua script
*/    
class LuaGameState : public GameState
{
private:
    
    //lua state
    
    //Scripting/Lua
    slua::State luaState_;

public:
    
    //script
    //init
    
    
};
    
    
} //end namespace spaceg


#endif



#pragma once
#ifndef __SPACEG_LUAGAMESTATE__
#define __SPACEG_LUAGAMESTATE__

#include <slua/State.hpp>
#include <slua/Context.hpp>

#include "../state/GameState.h"


namespace spaceg {

/**
* Lua Game States
* The class represents a game state which is controlled by a lua script
*/    
class LuaGameState : public GameState
{
private:
    
    //Scripting/Lua
    slua::State luaState_;
    
    slua::Context luaCtx_;
    
    //table for state representation

public:
	LuaGameState();
	
	LuaGameState(const char* const fileName);
	
	~LuaGameState();

	//register lua interfaces from engine to game
	void reg();

    
    //shared luastate?
    //LuaGameState(slua::State luaState) 
    
    //script
    //init
    
    
};
    
    
} //end namespace spaceg


#endif

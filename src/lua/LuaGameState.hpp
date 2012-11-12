


#pragma once
#ifndef __SPACEG_LUAGAMESTATE__
#define __SPACEG_LUAGAMESTATE__

#include <slua/State.hpp>
#include <slua/Bind.hpp>

#include "../state/BaseState.hpp"


namespace spaceg {

/**
* Lua Game States
* The class represents a game state which is controlled by a lua script
*/    
class LuaGameState : public BaseState
{
private:
    
    //Scripting/Lua
    slua::State luaState_;
    
    //table for state representation

public:
	LuaGameState();
	
	LuaGameState(const char* const fileName);
	
	~LuaGameState();
	
	
	//run()

	//register lua interfaces from engine to game
	void reg();
	
	
	//draw() call containing LuaGraphicsEntity

	//api for UI
    
    
    //shared luastate?
    //LuaGameState(slua::State luaState) 
    
    //script
    //init

	//LuaInterface
public:
	int getUISystem(slua::Context& ctx);	

    static const slua::RegStatus<LuaGameState> Bind;
};


    
    
} //end namespace spaceg


#endif




#pragma once
#ifndef __SPACEG_LUAGAMESTATE__
#define __SPACEG_LUAGAMESTATE__

#include <slua/State.hpp>
#include <slua/Bind.hpp>

#include "../state/BaseState.hpp"
#include "EngineContext.hpp"


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
    
    //Engine Interface
	EngineContext engineCtx_;
    
    //table for state representation
    
public:
	LuaGameState();
	~LuaGameState();
	
	/**
	* Load a lua file
	*/
	void loadFile(const char* const fileName);
		
	/**
	* Register the objects to lua vm
	*/
	void registerLuaInterface();
	
	/**
	* call main function
	*/
	void callMain();
	
	
	//call lua functions
	
	//draw() call containing LuaGraphicsEntity

	//api for UI
    
    
    //shared luastate?
    //LuaGameState(slua::State luaState) 
    
    //script
    //init
    
    //singleton

};


    
    
} //end namespace spaceg


#endif

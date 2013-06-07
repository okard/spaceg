


#pragma once
#ifndef __SPACEG_LUAGAMESTATE__
#define __SPACEG_LUAGAMESTATE__

#include <slua/State.hpp>
#include <slua/Bind.hpp>

#include "LuaBinder.hpp"
#include "LuaCamera.hpp"
#include "../state/State.hpp"

namespace spaceg {
	
class Application;

/**
* Lua Game States
* The class represents a game state which is controlled by a lua script
*/    
class LuaGameState : public State
{
private:
    //Scripting/Lua
    slua::State luaState_;
    
    //Binder Class Instance
    LuaBinder bind_;
    
    //Application reference
    Application& app_;
    
    LuaCamera cam_;
    
public:
	LuaGameState(Application& app);
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
	
	/**
    * Update the state
    */
    virtual void update(long timeElapsed);
        
    /**
    * Draw the state
    * rename to render
    */
    virtual void draw();
	
	
	//call lua functions
	
	//draw() call containing LuaGraphicsEntity

	//api for UI
    
    
    //shared luastate?
    //LuaGameState(slua::State luaState) 
    
    //script
    //init
    
    inline Application& getApplication() { return app_; }
    
    inline slua::State& getLuaState() { return luaState_; }

};


    
    
} //end namespace spaceg


#endif

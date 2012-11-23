

#pragma once
#ifndef __SPACEG_ENGINECONTEXT__
#define __SPACEG_ENGINECONTEXT__

#include <slua/Bind.hpp>


namespace spaceg {

/**
* General access layer for lua scripts
* To provide access to subsystems
* - Event Subsystem
* - Graphic Subsystem 
* - UI Subsystem
* - Audio Subsystem
*/
class EngineContext : public slua::LuaObject
{
private:
	//LuaGameState
	
public:

	int createUIDocument(slua::Context& ctx);
	//load ui font
	
	int createSpriteEntity(slua::Context& ctx);
	
	
	//Bind Table
	
	static const slua::BindStatus<EngineContext> bindStatus;
};


} //end namespace spaceg

#endif // __SPACEG_ENGINECONTEXT__

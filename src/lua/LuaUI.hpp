#pragma once
#ifndef __SPACEG_LUAUI__
#define __SPACEG_LUAUI__


#include <Rocket/Core/EventListener.h>

#include <slua/LuaRef.hpp>
#include <slua/LuaObject.hpp>

#include "LuaInterface.hpp"

namespace Rocket {
	namespace Core {
		class ElementDocument;
	}
}

namespace spaceg {
	
class Application;
class LuaGameState;
	
/**
* Lua UI Document
*/
class LuaUI : public slua::LuaObject, public Rocket::Core::EventListener
{
private:
	Rocket::Core::ElementDocument* element_;
	
	LuaGameState& lgstate_;
	Application& app_;
public:
	
	LuaUI(LuaGameState& lgstate);
	~LuaUI();
	
	// load a document from file
	int loadDocument(slua::Context& ctx);
	
	// add a event callback
	int addCallback(slua::Context& ctx);
	
	int enableDebugger(slua::Context& ctx);
	
	//set inner content?
	
	//DOM bindings?
	
	//setContent(id, format, text)
	
	//is visible
	//show
	//hide
	//close
	
	virtual void ProcessEvent(Rocket::Core::Event &event);
	
	//LuaInterface
	static const LuaBindInterface<LuaUI> luaInterface;
};
	
	
} //end namespace spaceg

#endif

#pragma once
#ifndef __SPACEG_LUAUI__
#define __SPACEG_LUAUI__

#include <string>
#include <unordered_map>

#include <Rocket/Core/EventListener.h>

#include <slua/LuaRef.hpp>

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
class LuaUI : public LuaClass, public Rocket::Core::EventListener
{
private:
	LuaGameState& lgstate_;
	
	Application& app_;
	
	Rocket::Core::ElementDocument* element_;
	
	std::unordered_map<std::string, slua::LuaRef> eventMap_;
public:
	
	LuaUI(LuaGameState& lgstate);
	~LuaUI();
	
	// load a document from file
	int loadDocument(slua::Context& ctx);
	
	// add a event callback
	int addCallback(slua::Context& ctx);
	
	/// is ui frame visible
	int isVisible(slua::Context& ctx);
	/// show ui frame
	int show(slua::Context& ctx);
	/// hide ui frame
	int hide(slua::Context& ctx);
	
	//set inner content?
	//font loading
	
	//DOM bindings?
	
	//setContent(id, format, text)
	
	//is visible
	//show
	//hide
	//close
	
	// enable debugger interface
	int enableDebugger(slua::Context& ctx);
	
	virtual void ProcessEvent(Rocket::Core::Event &event);
	
	//LuaInterface
	static const LuaBindInterface<LuaUI> luaInterface;
};
	
	
} //end namespace spaceg

#endif

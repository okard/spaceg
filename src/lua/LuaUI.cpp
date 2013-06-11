

#include "LuaUI.hpp"

#include <Rocket/Core/Event.h>
#include <Rocket/Debugger.h>

#include "LuaGameState.hpp"
#include "../Application.hpp"
#include "../GameException.hpp"

#include <iostream>

using namespace spaceg;

//Functions to bind
static const LuaBindFunction<LuaUI> lua_functions[]=
{
	//{"loadTexture", &LuaSpriteEntity::loadTexture},

	{"loadDocument", &LuaUI::loadDocument},
	{"addCallback", &LuaUI::addCallback},
	{"enableDebugger", &LuaUI::enableDebugger},
	{0,0}
};

//function context
const LuaBindInterface<LuaUI> LuaUI::luaInterface = 
{
	.metatableName = "UI",
	//.constructorName = nullptr,
	.registerHook = {nullptr, nullptr},
	.functions = lua_functions	
};


LuaUI::LuaUI(LuaGameState& lgstate)
	: lgstate_(lgstate)
	, app_(lgstate.getApplication())
	, element_(nullptr)
{
	
}

LuaUI::~LuaUI()
{
	
}

//load
int LuaUI::loadDocument(slua::Context& ctx)
{
	if(ctx.stackCount() != 2 
	|| !ctx.isType(2, slua::LuaType::STRING))
		throw GameException("Invalid call of LuaUI::loadDocument require 1 string argument");
		
	const char* fileName = ctx.getString(2);
	
	if(!element_)
	{
		element_ = app_.getUICtx()->LoadDocument(fileName);
		if (element_ != NULL)
			element_->Show();
	}
	
	return 0;
}


// add a event callback
int LuaUI::addCallback(slua::Context& ctx)
{
	if(ctx.stackCount() != 3
	|| !ctx.isType(2, slua::LuaType::STRING)
	|| !ctx.isType(3, slua::LuaType::FUNCTION)
	)
		throw GameException("Invalid call of LuaUI::addCallback require 1 string and 1 function argument");
	
	const char* eventName = ctx.getString(2);
	
	//addCallback("name", function)
	//std::map<string, LuaRef>
	
	if(element_)
	{
		//std::cout << "Add Listener: " << eventName << std::endl;
		element_->AddEventListener(eventName, this);
		//register eventName -> LuaRef 
		
		return 0;
	}
}

int LuaUI::enableDebugger(slua::Context& ctx)
{
	if(ctx.stackCount() != 2
	|| !ctx.isType(2, slua::LuaType::BOOLEAN)
	)
		throw GameException("Invalid call of LuaUI::enableDebuggerrequire 1 string and 1 function argument");
	
	bool debugState = ctx.getBoolean(2);
	Rocket::Debugger::SetVisible(debugState);
	return 0;
}

void LuaUI::ProcessEvent(Rocket::Core::Event &event)
{
	//std::cout << "[Debug] UIEvent: " << event.GetType().CString() << std::endl;
	//std::map<string, LuaRef>
		//process event 
			//event.GetParameters()->Size() 
			//add each parameter as lua parameter
}

/*
Unload the document by calling UnloadDocument() on its parent context.
document->GetContext()->UnloadDocument(document);
*/

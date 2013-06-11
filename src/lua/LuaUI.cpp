

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
	{"isVisible", &LuaUI::isVisible},
	{"show", &LuaUI::show},
	{"hide", &LuaUI::hide},
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
	for (const auto& em : eventMap_)
		const_cast<slua::LuaRef*>(&em.second)->unref();
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
		
		ctx.pushCopy(3);
		lua_State* const  luaState = ctx;
		eventMap_[eventName].set(luaState);
		
		return 0;
	}
}
/// is ui frame visible
int LuaUI::isVisible(slua::Context& ctx)
{
	if(element_)
		ctx.pushBool(element_->IsVisible());
	else
		ctx.pushBool(false);
		
	return 1;
}

/// show ui frame
int LuaUI::show(slua::Context& ctx)
{
	if(element_)
		element_->Show();
		
	return 0;
}

/// hide ui frame
int LuaUI::hide(slua::Context& ctx)
{
	if(element_)
		element_->Hide();
		
	return 0;
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
	const char* eventName = event.GetType().CString();
	
	auto got = eventMap_.find(eventName);
	if( got != eventMap_.end())
	{
		if(got->second.isSet())
		{
			got->second.push();
			
			auto pcount = event.GetParameters()->Size();
			auto ppushed = 0;
			for(int i=0; i< pcount; i++)
			{
				//TODO Requires a custom event instancer
				Rocket::Core::String str;
				Rocket::Core::Variant var;
				event.GetParameters()->Iterate(i, str, var);
				std::cout << "param key: " << str.CString() << std::endl;
				std::cout << "param type: " << (char)var.GetType() << std::endl;
				
			}
			//add each parameter as lua parameter
			lgstate_.getLuaState().getContext().call(0,0);
		}
	}
}

/*
Unload the document by calling UnloadDocument() on its parent context.
document->GetContext()->UnloadDocument(document);
*/

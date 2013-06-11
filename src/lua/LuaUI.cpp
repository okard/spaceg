

#include "LuaUI.hpp"

#include "LuaGameState.hpp"
#include "../Application.hpp"
#include "../GameException.hpp"


using namespace spaceg;


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
	/*
	Rocket::Core::ElementDocument* document = context->LoadDocument("../../assets/demo.rml");
	if (document != NULL)
		document->Show();
	*/
}


// add a event callback
int LuaUI::addCallback(slua::Context& ctx)
{
	//addCallback("name", function)
	//std::map<string, LuaRef>
	/*Rocket::Core::Element::AddEventListener 	( 	
	    const String &  	event,
		EventListener *  	listener,
		bool  	in_capture_phase = false	 
	)*/
	
}


void LuaUI::ProcessEvent(Rocket::Core::Event &event)
{
	//std::map<string, LuaRef>
		//process event 
			//event.GetParameters()->Size() 
			//add each parameter as lua parameter
}


/*
Unload the document by calling UnloadDocument() on its parent context.
document->GetContext()->UnloadDocument(document);
*/

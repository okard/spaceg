

#include "EngineContext.hpp"

using namespace spaceg;


static const slua::BindFunction<EngineContext> function[]=
{
	{"createUIDocument", &EngineContext::createUIDocument},
	{0,0}
};

const slua::BindStatus<EngineContext> EngineContext::bindStatus = 
{
	.className = "EngineContext",
	.Functions = function	
};


int EngineContext::createUIDocument(slua::Context& ctx)
{
	//get parameter
	//push UiDocument
	return 0;
}

int EngineContext::createSpriteEntity(slua::Context& ctx)
{
	
	return 0;
}

	


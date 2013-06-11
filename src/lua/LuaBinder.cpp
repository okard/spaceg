#include "LuaBinder.hpp"

#include "LuaGameState.hpp"

using namespace spaceg;


LuaBinder::LuaBinder(LuaGameState& state)
	: lgstate_(state), ctx_(state.getLuaState().getState())
{
}

LuaBinder::~LuaBinder()
{
	//iterate over all objects and detach it
	
}

//initialize storage
ObjectStorage<LuaClassPtr> LuaBinder::objects_;


//object id has to fit into lightuserdata
static_assert(sizeof(ObjectStorage<LuaClassPtr>::ObjectId) <= sizeof(slua::lightdata), "Invalid size of light user data");

#include "LuaBinder.hpp"

#include <slua/State.hpp>
#include "LuaGameState.hpp"

using namespace spaceg;


LuaBinder::LuaBinder(LuaGameState& state)
	: lgstate_(state), ctx_(state.getLuaState().getState())
{
}

LuaBinder::~LuaBinder()
{
	//iterate over all objects and detach it
	
	//detach all objects
	for(size_t i = 0; i<objects_.objCount(); i++)
		objects_[i].reset();
}


LuaGameState& LuaBinder::get(lua_State* state)
{
	auto s = slua::State::getState(state);
	auto se = static_cast<slua::StateEx<LuaGameState*>*>(s);
	return *se->get();
}


//initialize storage
ObjectStorage<LuaClassPtr> LuaBinder::objects_;


//object id has to fit into lightuserdata
static_assert(sizeof(ObjectStorage<LuaClassPtr>::ObjectId) <= sizeof(slua::lightdata), "Invalid size of light user data");



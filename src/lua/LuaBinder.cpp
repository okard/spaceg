#include "LuaBinder.hpp"

#include "LuaGameState.hpp"

using namespace spaceg;


LuaBinder::LuaBinder(LuaGameState& state)
	: lgstate_(state), ctx_(state.getLuaState().getState())
{
}

LuaBinder::~LuaBinder()
{
}

//initialize storage
ObjectStorage<slua::LuaObjectPtr> LuaBinder::objects_;


//object id has to fit into lightuserdata
static_assert(sizeof(ObjectStorage<slua::LuaObjectPtr>::ObjectId) <= sizeof(slua::lightdata), "Invalid size of light user data");
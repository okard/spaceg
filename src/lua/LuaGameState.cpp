

#include "LuaGameState.hpp"

#include "LuaSpriteEntity.hpp"
#include "LuaInput.hpp"

#include <slua/Context.hpp>

using namespace spaceg;


LuaGameState::LuaGameState()
{
}


LuaGameState::~LuaGameState()
{
}

void LuaGameState::loadFile(const char* const fileName)
{
	luaState_.LoadFile(fileName);
	luaState_.Execute();
}
	
		
void LuaGameState::registerLuaInterface()
{
	slua::Bind::Class<LuaSpriteEntity>(luaState_);
	LuaInput::reg(luaState_);
}

//Call "main" Function in Lua File
void LuaGameState::callMain()
{
	slua::Context& ctx = luaState_;
	ctx.pushGlobal("main");
	ctx.call(0,0);
}

// Update the state
void LuaGameState::update(long timeElapsed)
{
	slua::Context& ctx = luaState_;
	ctx.pushGlobal("update");
	ctx.pushInteger(timeElapsed);
	ctx.call(1,0);
}
	
//draw
void LuaGameState::draw()
{
	//call draw
	slua::Context& ctx = luaState_;
	ctx.pushGlobal("draw");
	ctx.call(0,0);
}



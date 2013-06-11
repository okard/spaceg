

#include "LuaGameState.hpp"

#include "../Application.hpp"

#include "LuaSpriteEntity.hpp"
#include "LuaUI.hpp"
#include "LuaInput.hpp"

#include <slua/Context.hpp>

#include <iostream>

using namespace spaceg;


LuaGameState::LuaGameState(Application& app)
	: app_(app)
	, luaState_(new slua::State())
	, bind_( new LuaBinder(*this))
	, cam_(std::make_shared<LuaCamera>(*this))
	, input_(std::make_shared<LuaInput>(*this))
{
}


LuaGameState::~LuaGameState()
{
	//call exit
	slua::Context& ctx = *luaState_;
	ctx.pushGlobal("exit");
	ctx.call(0,0);
	
	cam_.reset();
	input_.reset();
	bind_.reset();
	luaState_.reset();
}

void LuaGameState::loadFile(const char* const fileName)
{
	luaState_->LoadFile(fileName);
	luaState_->Execute();
}
	
		
void LuaGameState::registerLuaInterface()
{
	//custom binder
	//slua::Bind::Class<LuaSpriteEntity>(luaState_);
	bind_->registerObject<LuaCamera>(cam_, "camera");
	bind_->registerObject<LuaInput>(input_, "input");
	
	bind_->registerClass<LuaSpriteEntity>();
	bind_->registerClass<LuaUI>();
	//std::cout << "cam_ count: " << cam_.refCount() << std::endl;
	//std::cout << "input_ count: " << input_.refCount() << std::endl;
	
	//bind_.push(
}

//Call "main" Function in Lua File
void LuaGameState::callMain()
{
	slua::Context& ctx = *luaState_;
	ctx.pushGlobal("main");
	ctx.call(0,0);
}

// Update the state
void LuaGameState::update(long timeElapsed)
{
	slua::Context& ctx = *luaState_;
	ctx.pushGlobal("update");
	ctx.pushInteger(timeElapsed);
	ctx.call(1,0);
}
	
//draw
void LuaGameState::draw()
{
	//call draw
	slua::Context& ctx = *luaState_;
	ctx.pushGlobal("draw");
	ctx.call(0,0);
}



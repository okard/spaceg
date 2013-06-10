

#pragma once
#ifndef __SPACEG_LUACAMERA_HPP__
#define __SPACEG_LUACAMERA_HPP__

#include <slua/LuaRef.hpp>
#include <slua/LuaObject.hpp>
#include "LuaInterface.hpp"


namespace spaceg {

class LuaGameState;
class Application;

/**
* Lua Camera
*/
class LuaCamera : public slua::LuaObject
{
private:
	LuaGameState&  lgstate_;
	Application& app_;
	slua::LuaRef onChangeFunc_;
	
public:
	LuaCamera(LuaGameState& lgstate);
	~LuaCamera();
	
	int getView(slua::Context& ctx);
	int zoom(slua::Context& ctx);
	int rotate(slua::Context& ctx);
	int move(slua::Context& ctx);
	int onChange(slua::Context& ctx);
	
private:
	inline void fireUpdate();
public:
	static const LuaBindInterface<LuaCamera> luaInterface;
};

} //end namespace spaceg

#endif // __SPACEG_LUACAMERA_HPP__

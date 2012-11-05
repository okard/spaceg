



#pragma once
#ifndef __SPACEG_LUASPRITEENTITY__
#define __SPACEG_LUASPRITEENTITY__


namespace spaceg {
	
class LuaSpriteEntity
{
private:
public:

	//filename
	void loadTexture();
	
	//load shader
	void loadShader();
	
	//shaderArguments?
	
	//float x, float y, float rotation, float scale_x, float scale_y, color?
	void draw();
	
};




} //end namespace spaceg


#endif

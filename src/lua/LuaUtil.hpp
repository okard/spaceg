
#pragma once
#ifndef __SPACEG_LUAUTIL__
#define __SPACEG_LUAUTIL__

namespace spaceg {
	

/**
* Lua doesn't support floating points but SFML works with floats so
* make a 1000 precision conversion 
* 1.000 == 1000
* 1.123 == 1123 
*/
inline int luaFloat2Int(float f)
{
	return (f*1000.0f);
}

/**
* Lua doesn't support floating points but SFML works with floats so
* make a 1000 precision conversion 
* 1.000 == 1000
* 1.123 == 1123 
*/
inline float luaInt2Float(int i)
{
	float ii = i;
	return (ii / 1000.0f);
}
	
	
} //end namespace spaceg

#endif

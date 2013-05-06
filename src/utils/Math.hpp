
#pragma once
#ifndef __SPACEG_UTILSMATH_HPP__
#define __SPACEG_UTILSMATH_HPP__

namespace spaceg {

template<typename T>
inline T clamp(T v, T min, T max)
{
	return v < min ? min : v > max ? max : v;
}
	
	
} // end namespace spaceg

#endif //__SPACEG_UTILSMATH_HPP__

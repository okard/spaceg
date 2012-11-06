
#pragma once
#ifndef __SPACEG_GEOMETRY__
#define __SPACEG_GEOMETRY__

namespace spaceg {

/**
* A simple point
*/
template<typename T>
class Point
{
private:
    T x, y;
public:
    
};
    
/**
* A rect
*/
template<typename T>
class Rect
{
private:
    T x, y, w, h;
public:

	void setSize(T w, T h)
	{
		this.w = w;
		this.h = h;
	}
	
	void setPosition(T x, T y)
	{
		this.x = x;
		this.y = y;
	}

	//move

    
};

//View or Camera 
//Required for world rendering
typedef Rect<float> View;
typedef Rect<float> Rectf;

    
} //end namespace spaceg


#endif // __SPACEG_GEOMETRY__

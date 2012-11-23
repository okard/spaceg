
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
	Rect()
		: x(0), y(0), w(0), h(0)
	{
	}

	Rect(const Rect<T>& r)
	{
		x = r.x; y = r.y;
		w = r.w; h = r.h;
	}
	
	Rect<T>& operator= (const Rect<T> r)
    {
        if (this != &r)
        {
			x = r.x; y = r.y;
			w = r.w; h = r.h;
		}
		return *this;
	}

	void setSize(T w, T h)
	{
		this->w = w;
		this->h = h;
	}
	
	void setPosition(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	T getX()
	{
		return x;
	}
	
	T getY()
	{
		return y;
	}
	
	T getWidth()
	{
		return w;
	}

	T getHeight()
	{
		return h;
	}

	//move

    
};


//Predefinitions:

//View or Camera 
//Required for world rendering
typedef Rect<float> View;
typedef Rect<float> Rectf;

    
} //end namespace spaceg


#endif // __SPACEG_GEOMETRY__

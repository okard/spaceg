
#pragma once
#ifndef __SPACEG_STATE__
#define __SPACEG_STATE__


namespace spaceg {
    
class Application;
    
/**
* State Interface
*/   
class State
{
private:
    
    
public:
    virtual ~State() {}
    
    //activate
    virtual void activate(Application* const app){}
    
    //disable
    virtual void disable(){}
    
    //update
    virtual void update(long timeElapsed) = 0;
        
    //draw
    virtual void draw() = 0;
    
};
    
    
} //end namespace spaceg




#endif // __SPACEG_STATE__

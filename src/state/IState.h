
#pragma once
#ifndef __SPACEG_ISTATE__
#define __SPACEG_ISTATE__


namespace spaceg {
    
class Application;
    
/**
* State Interface
*/   
class IState
{
private:
    
    
public:
    virtual ~IState() {}
    
    //Initialize
    //Hold
    //Resume
    //Destroy
    
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

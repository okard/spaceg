
#pragma once
#ifndef __SPACEG_STATE__
#define __SPACEG_STATE__


namespace spaceg {
    
/**
* State Interface
*/   
class State
{
private:
    
    
public:
    virtual ~State() {}
    
    //update
    virtual void update(long timeElapsed) = 0;
        
    //draw
    virtual void draw() = 0;
    
};
    
    
} //end namespace spaceg




#endif // __SPACEG_STATE__

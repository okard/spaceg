
#pragma once
#ifndef __SPACEG_ISTATE__
#define __SPACEG_ISTATE__


namespace spaceg {
	
//TODO Event Life Cycle

enum class StateStatus
{
	New,	  // created
	Active,   // running
	OnHold,   // disabled/pause
	Disposed  //destroyed
};
	
    
/**
* State Interface
*/   
class State
{
private:
	StateStatus status_;
    
public:
    /**
    * Destructs state finally
    */
    virtual ~State() {}
    
    
    //virtual void initialize();
    //virtual void dispose();
    
    //Hold
    //Resume
    
    /**
    * Activate state and attach to application
    * TODO Rename? run
    * TODO Remove Application reference
    */
    virtual void activate(){}
    
    /**
    * Disable state
    *TODO Rename? stop
    */
    virtual void disable(){}
    
    /**
    * Update the state
    */
    virtual void update(long timeElapsed) = 0;
        
    /**
    * Draw the state
    * rename to render
    */
    virtual void draw() = 0;
    
    //isInitialized   
    
    inline StateStatus getStatus() const { return status_; }
};
    
    
} //end namespace spaceg




#endif // __SPACEG_STATE__

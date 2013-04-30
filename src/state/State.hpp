
#pragma once
#ifndef __SPACEG_ISTATE__
#define __SPACEG_ISTATE__


namespace spaceg {
	
//TODO Event Life Cycle
    
/**
* State Interface
*/   
class State
{
public:
	enum Status
	{
		UnInitialized,
		Active,
		Holded, //disabled
		Disposed
	};

private:
    
    
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
};
    
    
} //end namespace spaceg




#endif // __SPACEG_STATE__


#pragma once
#ifndef __SPACEG_ISTATE__
#define __SPACEG_ISTATE__


namespace spaceg {
    
class Application;
    
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
		Holded,
		Disposed
	};

private:
    
    
public:
    /**
    * Destructs state finally
    */
    virtual ~State() {}
    
    //Initialize
    //Hold
    //Resume
    //Destroy/Dispose
    
    /**
    * Activate state and attach to application
    *TODO Rename?
    */
    virtual void activate(Application* const app){}
    
    /**
    * Disable state
    *TODO Rename?
    */
    virtual void disable(){}
    
    /**
    * Update the state
    */
    virtual void update(long timeElapsed) = 0;
        
    /**
    * Draw the state
    */
    virtual void draw() = 0;
    
};
    
    
} //end namespace spaceg




#endif // __SPACEG_STATE__

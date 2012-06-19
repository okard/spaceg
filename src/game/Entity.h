

#pragma once
#ifndef __SPACEG_ENTITY__
#define __SPACEG_ENTITY__

namespace spaceg {
    
/**
* Basic Game Entity
*/
class Entity
{
protected:
    bool static_;
    bool active_;
    
    //request update
public:  
    /**
    * Return true if entity requires an update
    */
    virtual bool requestUpdate();
    
    /**
    * Update entity with current elapsed time
    */
    virtual void update(long timeElapsed);
    
};




//GraphicEntity has a Sprite?
    
} //end namespace spaceg

#endif
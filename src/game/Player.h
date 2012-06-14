

#pragma once
#ifndef __SPACEG_PLAYER__
#define __SPACEG_PLAYER__

#include <string>

#include "Entity.h"


namespace spaceg {

/**
* Player class
*/
class Player
{
private:
    std::string name_;
    
    //current resource points
    //current level
    
    //Ships controlled by the player
    //std::vector<Ship> ships_;
    
    
public:
    Player();
    ~Player();
    
};

} //end namespace spaceg


#endif //__SPACEG_PLAYER__
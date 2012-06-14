
#pragma once
#ifndef __SPACEG_SHIP__
#define __SPACEG_SHIP__

#include <string>

#include "Entity.h"


namespace spaceg {
    

/**
* Space Ship Entity
*/
class Ship : public Entity
{
public:
    /**
    * Ship Types
    */
    enum ShipType
    {
        STYPE_CARGO,
        STYPE_SPEED,
        STYPE_LIGHT_MILITARY
    };
    
private:
    //logic
    
    //ShipID
    
    //Ship Type see above
    ShipType type_;
    //Shipname
    std::string name_;
    //maximum load
    int maxWeight_ = 0;
    //maximum speed
    int maxSpeed_ = 0;
    //acceleration
    float acc_=0.2f;
    
    //Current Status values
    
    //currentSpeed
    int currentSpeed_ = 0;
    int health_ = 100;

    //Weapons/Equip
    //the containing weapons and equipment
      
public:
};


} //end namespace spaceg

#endif //__SPACEG_SHIP__


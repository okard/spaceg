

--[[
Ship = Entity();

Ship.sprite = SpriteEntity();


//logic
    
    //ShipID
    
    //Ship Type see above
    ShipType type_;
    
    //engine type?
    
    //Shipname
    std::string name_;
    //weapon slots
    short slots_;
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
    
    //current actions/behavior/command
        //-> attack, protect, move to -> lower level
        //-> escort -> higher level
    //current flotte/division

    //Weapons/Equip
    //the containing weapons and equipment

--]]

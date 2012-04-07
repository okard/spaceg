

#pragma once
#ifndef __SPACEG_SYSTEMINTERFACE__
#define __SPACEG_SYSTEMINTERFACE__

#include <Rocket/Core/SystemInterface.h>

#include <SFML/System/Clock.hpp>


namespace spaceg {

    
class SystemInterface : public Rocket::Core::SystemInterface 
{
private:
    sf::Clock clock_;
    
public:
    // Get the number of seconds elapsed since the start of the application.
    virtual float GetElapsedTime();
};
    

} // end namespace spaceg








#endif //__SPACEG_SYSTEMINTERFACE__
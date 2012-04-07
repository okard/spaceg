
#pragma once
#ifndef __SPACEG_SHIP__
#define __SPACEG_SHIP__

#include <string>

#include <SFML/Graphics.hpp>


namespace spaceg {
    

/**
* Space Ship Entity
*/
class Ship
{
private:
    //logic
    std::string name_;
    int speed_ = 0;
    
    //graphic
    sf::Sprite sprite_;
    
public:
    
    void draw(const sf::RenderTexture* renderTexture);
};


} //end namespace spaceg

#endif //__SPACEG_SHIP__


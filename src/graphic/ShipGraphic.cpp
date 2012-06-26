
#include "ShipGraphic.hpp"

#include "../game/Ship.h"

using namespace spaceg;


ShipGraphic::ShipGraphic(Ship* const ship)
    : ship_(ship)
{
    
}

ShipGraphic::~ShipGraphic()
{
    
}

void ShipGraphic::update(long timeElapsed)
{
    ship_->update(timeElapsed);
}
    
void ShipGraphic::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
    
}

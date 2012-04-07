

#include "SystemInterface.h"


using namespace spaceg;



float SystemInterface::GetElapsedTime()
{
    return clock_.getElapsedTime().asSeconds();
}
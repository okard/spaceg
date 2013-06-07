

#include "SfmlSystemInterface.hpp"


using namespace spaceg;



float SfmlSystemInterface::GetElapsedTime()
{
    return clock_.getElapsedTime().asSeconds();
}

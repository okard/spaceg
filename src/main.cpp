

#include "Application.h"
#include "Exception.h"

#include "lua/LuaGameState.h"

#include "state/GameState.h"
#include "graphic/NebulaGraphic.h"
 
using namespace spaceg;

int main(int argc, char **argv)
{
    //Parse commandline options
    //-main script(lua) file to run?
    //-log outputs?
    
    //load settings? fullscreen/resolution
    
    Application app;
    
    //test stuff
    GameState MyState;
    sf::Texture nebulaTex;
    NebulaGraphic nebula;
    if(!nebulaTex.loadFromFile("data/img/nebula2.png"))
        throw GameException("file load failed");
    nebula.setTexture(&nebulaTex);
    nebula.random();
    MyState.attach(&nebula);
    
    LuaGameState state;
    app.switchState(&MyState);
    app.run();

    return EXIT_SUCCESS;
}
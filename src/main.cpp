

#include "Application.h"
#include "GameException.hpp"
#include "ResourceManager.h"

#include "lua/LuaGameState.h"

#include "state/GameState.h"
#include "graphic/NebulaGraphic.h"
#include "game/World.h"
#include "graphic/WorldGraphic.hpp"
 
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
    
    //nebula test
    sf::Texture* nebulaTex = TexResMng::getInstance().retrieve("data/img/nebula2.png");
    NebulaGraphic nebula;
    nebula.setTexture(nebulaTex);
    nebula.generate(251307725);
    
    NebulaGraphic nebula2;
    nebula2.setTexture(nebulaTex);
    nebula2.generate(2807516958);
    
    //world graphic test:
    sf::Texture* starfield = TexResMng::getInstance().retrieve("data/img/starfield01.png");
    World w;
    WorldGraphic world(&w);
    world.setSpaceFieldTexture(starfield);
    
    MyState.attach(&world);
    MyState.attach(&nebula);
    MyState.attach(&nebula2);
    
    
    LuaGameState state;
    app.switchState(&MyState);
    app.run();

    return EXIT_SUCCESS;
}
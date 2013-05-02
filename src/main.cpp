

#include "Application.hpp"
#include "GameException.hpp"
#include "ResourceManager.h"
#include "Log.hpp"

#include "lua/LuaGameState.hpp"

#include "state/BaseState.hpp"
#include "render/NebulaGraphic.h"
#include "game/World.hpp"
#include "render/WorldGraphic.hpp"
 
using namespace spaceg;


int main(int argc, char **argv)
{
	//Register Logging:
	cul::Log::onLog().connect(engine_logger);
	cul::Log::Source().verbose("program started");
	
    //Parse commandline options
    //-main script(lua) file to run?
    //-log outputs?
    
    //load settings? fullscreen/resolution
    //audio on off
    
    Application app;
    
    /*
    //test stuff
    BaseState MyState;
    
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
    
    View v;
    World w(v);
    WorldGraphic world(&w);
    world.setSpaceFieldTexture(starfield);
    
    MyState.attach(&world);
    MyState.attach(&nebula);
    MyState.attach(&nebula2);
    */
    
    // Running a Lua Game State
    LuaGameState state;
    state.setApplication(&app);
    state.loadFile("data/lua/main.lua");
    state.callMain();
    app.switchState(&state);
    app.run();

    return EXIT_SUCCESS;
}

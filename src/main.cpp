

#include "Application.h"

#include "lua/LuaGameState.h"
 
using namespace spaceg;

int main(int argc, char **argv)
{
    //Parse commandline options
    //-main script(lua) file to run?
    //-log outputs?
    
    //load settings? fullscreen/resolution
    
    Application app;
    
    LuaGameState state;
    app.switchState(&state);
    app.run();

    return EXIT_SUCCESS;
}
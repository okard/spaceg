

#include "Application.h"
 
using namespace spaceg;

int main(int argc, char **argv)
{
    //Parse commandline options
    //-main script(lua) file to run?
    //-log outputs?
    
    Application app;
    app.run();

    return EXIT_SUCCESS;
}
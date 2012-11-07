
#pragma once
#ifndef __SPACEG_WORLD__
#define __SPACEG_WORLD__

#include "../base/Geometry.hpp"

namespace spaceg {

/**
* World Presentation
*/
class World 
{
private:
	View& view_;

    
    //world size is mapped to float x, y
    
    //within a trashhold position is set back when over a chunk
    
    
    //chunks?
    
    //WorldChunk
    
    //two layer?
        //space and detail near planets and nebulas
        
    //combine background starfield and planets and nebulas
        //create a big big map
        
    //entities in current chunk
    
    //simple tree?
    
    //load nebulas from file
    
public:
	World(View& view);
	~World();
    
    
};
    
}

#endif //__SPACEG_WORLD__

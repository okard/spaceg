


#pragma once
#ifndef __SPACEG_RESOURCEMANAGER__
#define __SPACEG_RESOURCEMANAGER__

namespace spaceg {

/**
* Manage resource type T over key K
*/
template <class T, class K=T>    
class ResourceManager
{
private:
    //hotloading change events for files?
    
public:
    
    //load a resource for key K
    void load(K k);
    
    //retrieve T for k
    T retrieve(K k);
};

//for sf:.Image
//for sf::Texture?


} //end namespace spaceg

#endif



#pragma once
#ifndef __SPACEG_RESOURCEMANAGER__
#define __SPACEG_RESOURCEMANAGER__

#include <map>


namespace spaceg {

/**
* Manage resource type T over key K
*/
template <class T, class K=T>    
class ResourceManager
{
private:
    //hotloading change events for files?
    
    //store
    std::map<K,T> store_;
    
public:
    //lambda for loading?
    
    //load a resource for key K
    void load(K k);
    
    //bool contains?
    //set()
    
    //retrieve T for k
    T retrieve(K k);
};

//for sf:.Image
//for sf::Texture?  <sf::Texture*, std::string>


} //end namespace spaceg

#endif



#pragma once
#ifndef __SPACEG_RESOURCEMANAGER__
#define __SPACEG_RESOURCEMANAGER__

#include <map>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "GameException.hpp"


namespace spaceg {

/**
* Manage resource type T over key K
*/
template <class T, class K=T>    
class ResourceManager
{
private:
    //store
    std::map<K,T> store_;
    
    
    //Loader function
    typedef T (*LoaderFunc)(const K&);
    static const LoaderFunc loaderF_;
    
    
    //clear function
    
private:
    
    ResourceManager() {}
    ResourceManager(const ResourceManager&) {}
    ResourceManager& operator=(const ResourceManager&) { return *this; }
    ~ResourceManager() {}
      
public:
    
    static ResourceManager& getInstance()
    {
        static ResourceManager instance; 
        return instance; 
    }
    
    static ResourceManager& getInstancePtr()
    {
        return &getInstance();
    }
    
      

    template<LoaderFunc ff>
    T retrieve(K k)
    {
        if(!ff)
            throw GameException("Error no loader function for resource manager");
        
         //TODO exception handling
        
        if(store_.find(k) == store_.end())
        {
            auto value = ff(k);
            store_.insert(std::pair<K,T>(k, value));
        }
            
        return store_[k];
    }
    
    //retrieve T for k
    T retrieve(K k)
    {
        return retrieve<ResourceManager::loaderF_>(k);
    }
};


sf::Texture* textureLoader(const std::string&);

typedef ResourceManager<sf::Texture*, std::string>  TexResMng;


//for sf:.Image
//for sf::Texture?  <sf::Texture*, std::string>


} //end namespace spaceg

#endif
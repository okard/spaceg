


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
    
    //Function Types
    typedef T (*LoaderFunc)(const K&);
    typedef void (*DestructFunc)(T);
    
    
    static const LoaderFunc loaderF_;
    static const DestructFunc destructF_; 
    
private:
    
    ResourceManager() {}
    ResourceManager(const ResourceManager&) {}
    ResourceManager& operator=(const ResourceManager&) { return *this; }
    ~ResourceManager() 
    {
		clear();
	}
      
public:
    
    /**
    * Get instance reference
    */
    static ResourceManager& getInstance()
    {
        static ResourceManager instance; 
        return instance; 
    }
    
    /**
    * Get instance pointer
    */
    static ResourceManager& getInstancePtr()
    {
        return &getInstance();
    }
    
    /**
    * Retrieve the value for key with a specialized loader
    */
    template<LoaderFunc f>
    T const retrieve(K k)
    {
        return retrieve(k, f);
    }
    
    /**
    * Retrieve value to key with default loader function
    */
    T const retrieve(K k)
    {
        return retrieve(k, loaderF_);
    }
    
    /**
    * Clean up a key
    */
    void clear(K k)
    {
        auto it = store_.find(k);
        
        if(it != store_.end()
        && destructF_)
            destructF_(*it);
        
        store_.erease(it);
    }
    
    
    /**
    * Clean up all
    */
    void clear()
    {
        
    }
    
private:
    
    inline T const retrieve(K k, LoaderFunc pLoader)
    {
        if(!pLoader)
            throw GameException("Error no loader function for resource manager");
        
         //TODO exception handling
        
        if(store_.find(k) == store_.end())
        {
            auto value = pLoader(k);
            store_.insert(std::pair<K,T>(k, value));
        }
            
        return store_[k];
    }
    
     
    
};

typedef ResourceManager<sf::Texture*, std::string>  TexResMng;


//for sf:.Image
//for sf::Texture?  <sf::Texture*, std::string>
//Audio


} //end namespace spaceg

#endif

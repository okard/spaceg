
#include "ResourceManager.h"

using namespace spaceg;

namespace spaceg { sf::Texture* textureLoader(const std::string&); }

template <> 
const TexResMng::LoaderFunc TexResMng::loaderF_ = &textureLoader;


sf::Texture* spaceg::textureLoader(const std::string& filename)
{
    auto tex = new sf::Texture();
    if(!tex->loadFromFile (filename))
    {
        throw GameException("Failed to load texture from image");
    }
    return tex;
}
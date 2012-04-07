
#pragma once
#ifndef __SPACEG_RENDERINTERFACE__
#define __SPACEG_RENDERINTERFACE__

#include <boost/shared_ptr.hpp>

#include <Rocket/Core/RenderInterface.h>
#include <SFML/Graphics/RenderWindow.hpp>

namespace spaceg {
    
/**
* libRocket Render Interface
*/
class RenderInterface : public Rocket::Core::RenderInterface 
{
public:
    RenderInterface(boost::shared_ptr<sf::RenderWindow> window);

    void prepare();
    void resize();

    virtual void RenderGeometry(Rocket::Core::Vertex* vertices, int verticesCount, int* indices, int indicesCount, Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation);
    
    virtual Rocket::Core::CompiledGeometryHandle CompileGeometry(Rocket::Core::Vertex* vertices, int verticesCount, int* indices, int indicesCount, Rocket::Core::TextureHandle texture);
    
    virtual void RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation);
    
    virtual void ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry);
    
    virtual void EnableScissorRegion(bool enable);
    
    virtual void SetScissorRegion(int x, int y, int width, int height);
    
    virtual bool LoadTexture(Rocket::Core::TextureHandle& textureHandle, Rocket::Core::Vector2i& textureDimensions, const Rocket::Core::String& source);
    
    virtual bool GenerateTexture(Rocket::Core::TextureHandle& textureHandle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& sourceDimensions);
    
    virtual void ReleaseTexture(Rocket::Core::TextureHandle texture);

private:
    boost::shared_ptr<sf::RenderWindow> m_window;
};

} //end namespace spaceg

#endif //__SPACEG_RENDERINTERFACE__
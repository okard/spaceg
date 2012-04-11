
#pragma once
#ifndef __SPACEG_RENDERINTERFACE__
#define __SPACEG_RENDERINTERFACE__

#include <Rocket/Core/RenderInterface.h>

namespace sf { 
    class RenderTarget;
}

namespace spaceg {
    
/**
* libRocket Render Interface
*/
class RenderInterface : public Rocket::Core::RenderInterface 
{
private:
    sf::RenderTarget* target_;
    
public:
    RenderInterface(sf::RenderTarget* target);
    ~RenderInterface();

    void startRender();
    void finishRender();

    virtual void RenderGeometry(Rocket::Core::Vertex* vertices, int verticesCount, int* indices, int indicesCount, Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation);
    
    virtual Rocket::Core::CompiledGeometryHandle CompileGeometry(Rocket::Core::Vertex* vertices, int verticesCount, int* indices, int indicesCount, Rocket::Core::TextureHandle texture);
    
    virtual void RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation);
    
    virtual void ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry);
    
    virtual void EnableScissorRegion(bool enable);
    
    virtual void SetScissorRegion(int x, int y, int width, int height);
    
    virtual bool LoadTexture(Rocket::Core::TextureHandle& textureHandle, Rocket::Core::Vector2i& textureDimensions, const Rocket::Core::String& source);
    
    virtual bool GenerateTexture(Rocket::Core::TextureHandle& textureHandle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& sourceDimensions);
    
    virtual void ReleaseTexture(Rocket::Core::TextureHandle texture);

};

} //end namespace spaceg

#endif //__SPACEG_RENDERINTERFACE__
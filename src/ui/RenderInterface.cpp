
#include "RenderInterface.h"

#include <Rocket/Core/Core.h>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

using namespace spaceg;


struct SfmlRenderGeometry
{
    sf::Texture* texture;
    sf::VertexArray vertices;
};



RenderInterface::RenderInterface(sf::RenderTarget* Window)
{
    target_ = Window;
}

RenderInterface::~RenderInterface()
{
}

void RenderInterface::startRender()
{
    target_->pushGLStates();    
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}

void RenderInterface::finishRender()
{
    target_->popGLStates();
}

// Called by Rocket when it wants to render geometry that it does not wish to optimise.
void RenderInterface::RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, const Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation)
{
    //std::cerr << "RenderInterface::RenderGeometry" << std::endl;
    //std::cerr << "num_vertices: " <<  num_vertices << " num_indices: " << num_indices << std::endl;
    //std::cerr << "tex: " << texture << std::endl;
    
    auto tex = reinterpret_cast<sf::Texture*>(texture);   
    auto texWidth = !tex ? 1 : tex->getWidth();
    auto texHeight = !tex ? 1 : tex->getHeight();
    
    sf::VertexArray triangles(sf::Triangles, num_indices);
    
    for(int i=0; i < num_indices; i++)
    {
        auto vert = vertices[indices[i]];
        
        triangles[i].position = sf::Vector2f(vert.position.x, vert.position.y);
        if(tex)
            triangles[i].texCoords = sf::Vector2f(vert.tex_coord.x*texWidth, vert.tex_coord.y*texHeight);
        triangles[i].color = sf::Color(vert.colour.red, vert.colour.green, vert.colour.blue, vert.colour.alpha);
    }
    
    //render state blend and transform
    sf::RenderStates state;
    state.transform.translate(translation.x, translation.y);
    state.blendMode = sf::BlendAlpha; 
    state.texture = tex;
    
    target_->draw(triangles, state);
}

// Called by Rocket when it wants to compile geometry it believes will be static for the forseeable future.     
Rocket::Core::CompiledGeometryHandle RenderInterface::CompileGeometry(Rocket::Core::Vertex* vertices,
                                                                           int num_vertices, int* indices,
                                                                           int num_indices,
                                                                           const Rocket::Core::TextureHandle texture)
{
    //std::cerr << "RenderInterface::CompileGeometry" << std::endl;
    
    auto tex = reinterpret_cast<sf::Texture*>(texture);  
    auto texWidth = !tex ? 1 : tex->getWidth();
    auto texHeight = !tex ? 1 : tex->getHeight();
    
    SfmlRenderGeometry* geometry = new SfmlRenderGeometry();
    geometry->texture = tex;
    geometry->vertices.setPrimitiveType(sf::Triangles);
    geometry->vertices.resize(num_indices);
    
    for(int i=0; i < num_indices; i++)
    {
        auto vert = vertices[indices[i]];
        
        geometry->vertices[i].position = sf::Vector2f(vert.position.x, vert.position.y);
        if(tex)
            geometry->vertices[i].texCoords = sf::Vector2f(vert.tex_coord.x*texWidth, vert.tex_coord.y*texHeight);
        geometry->vertices[i].color = sf::Color(vert.colour.red, vert.colour.green, vert.colour.blue, vert.colour.alpha);
    }
    
    //std::cerr << "Compiled: " << geometry << " Count: " << geometry->vertices.getVertexCount() << " tex: " << geometry->texture << std::endl;
    
    return reinterpret_cast<Rocket::Core::CompiledGeometryHandle>(geometry);
}

// Called by Rocket when it wants to render application-compiled geometry.      
void RenderInterface::RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation)
{
    auto geo = reinterpret_cast<SfmlRenderGeometry*>(geometry);
    
    //std::cerr << "Render Compiled: " << geo << " Count: " << geo->vertices.getVertexCount() << " tex: " << geo->texture << std::endl;
    
    //render state blend and transform
    sf::RenderStates state;
    state.transform.translate(translation.x, translation.y);
    state.blendMode = sf::BlendAlpha; 
    state.texture = geo->texture;
    target_->draw(geo->vertices, state);
}

// Called by Rocket when it wants to release application-compiled geometry.     
void RenderInterface::ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry)
{
    delete reinterpret_cast<SfmlRenderGeometry*>(geometry);    
}

// Called by Rocket when it wants to enable or disable scissoring to clip content.      
void RenderInterface::EnableScissorRegion(bool enable)
{
    //std::cerr << "Enable Scissor" << std::endl;
    if (enable)
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);
}

// Called by Rocket when it wants to change the scissor region.     
void RenderInterface::SetScissorRegion(int x, int y, int width, int height)
{
    //std::cerr << "Set Scissor Reg" << std::endl;
    glScissor(x, target_->getSize().y - (y + height), width, height);
}

// Called by Rocket when a texture is required by the library.      
bool RenderInterface::LoadTexture(Rocket::Core::TextureHandle& texture_handle, Rocket::Core::Vector2i& texture_dimensions, const Rocket::Core::String& source)
{
    //std::cerr << "RenderInterface::LoadTexture: " << source.CString() << std::endl;
    
    sf::Texture *image = new sf::Texture();
    if(!image->loadFromFile(source.CString()))
    {
        delete image;
        return false;
    };
    
    texture_handle = reinterpret_cast<Rocket::Core::TextureHandle>(image);
    texture_dimensions = Rocket::Core::Vector2i(image->getWidth(), image->getHeight());

    return true;
}

// Called by Rocket when a texture is required to be built from an internally-generated sequence of pixels.
bool RenderInterface::GenerateTexture(Rocket::Core::TextureHandle& texture_handle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& source_dimensions)
{
    //std::cerr << "RenderInterface::GenerateTexture:" << source_dimensions.x << " " << source_dimensions.y << std::endl;
    
    sf::Texture *texture = new sf::Texture();
    if (!texture->create(source_dimensions.x, source_dimensions.y)) 
    {
        delete texture;
        return false;
    }
    texture->update(source, source_dimensions.x, source_dimensions.y, 0, 0);
    texture_handle = reinterpret_cast<Rocket::Core::TextureHandle>(texture);
   
    return true;
}

// Called by Rocket when a loaded texture is no longer required.        
void RenderInterface::ReleaseTexture(Rocket::Core::TextureHandle texture_handle)
{
    delete reinterpret_cast<sf::Texture*>(texture_handle);
}
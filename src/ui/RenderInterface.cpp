
#include "RenderInterface.h"

#include <Rocket/Core/Core.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>


using namespace spaceg;

RenderInterface::RenderInterface(sf::RenderWindow* Window)
{
    window_ = Window;
    this->resize();
}

void RenderInterface::resize()
{
    window_->setActive(true);

    auto wsize = window_->getSize();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, wsize.x, wsize.y, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glViewport(0, 0, wsize.x, wsize.y);
};

// Called by Rocket when it wants to render geometry that it does not wish to optimise.
void RenderInterface::RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, const Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation)
{
    //std::cerr << "RenderInterface::RenderGeometry" << std::endl;
    //std::cerr << "num_vertices: " <<  num_vertices << " num_indices: " << num_indices << std::endl;
    
    glPushMatrix();
    glTranslatef(translation.x, translation.y, 0);

    std::vector<Rocket::Core::Vector2f> Positions(num_vertices);
    std::vector<Rocket::Core::Colourb> Colors(num_vertices);
    std::vector<Rocket::Core::Vector2f> TexCoords(num_vertices);

    for(int  i = 0; i < num_vertices; i++)
    {
        Positions[i] = vertices[i].position;
        Colors[i] = vertices[i].colour;
        TexCoords[i] = vertices[i].tex_coord;
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glVertexPointer(2, GL_FLOAT, 0, &Positions[0]);
    glColorPointer(4, GL_UNSIGNED_BYTE, 0, &Colors[0]);
    glTexCoordPointer(2, GL_FLOAT, 0, &TexCoords[0]);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    sf::Texture *sfTexture = (sf::Texture *)texture;

    if(sfTexture) 
    {
        sfTexture->bind();
    } 
    else 
    {
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glBindTexture(GL_TEXTURE_2D, 0);
    };

    glDrawElements(GL_TRIANGLES, num_indices, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glColor4f(1, 1, 1, 1);

    glPopMatrix();
}

// Called by Rocket when it wants to compile geometry it believes will be static for the forseeable future.     
Rocket::Core::CompiledGeometryHandle RenderInterface::CompileGeometry(Rocket::Core::Vertex* vertices,
                                                                           int num_vertices, int* indices,
                                                                           int num_indices,
                                                                           const Rocket::Core::TextureHandle texture)
{
    std::cerr << "RenderInterface::CompileGeometry" << std::endl;
    
    
    return NULL;
}

// Called by Rocket when it wants to render application-compiled geometry.      
void RenderInterface::RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation)
{
 
}

// Called by Rocket when it wants to release application-compiled geometry.     
void RenderInterface::ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry)
{

    
}

// Called by Rocket when it wants to enable or disable scissoring to clip content.      
void RenderInterface::EnableScissorRegion(bool enable)
{
    //std::cerr << "Enable Scissor" << std::endl;
    
}

// Called by Rocket when it wants to change the scissor region.     
void RenderInterface::SetScissorRegion(int x, int y, int width, int height)
{
    //std::cerr << "Set Scissor Reg" << std::endl;
    
}

// Called by Rocket when a texture is required by the library.      
bool RenderInterface::LoadTexture(Rocket::Core::TextureHandle& texture_handle, Rocket::Core::Vector2i& texture_dimensions, const Rocket::Core::String& source)
{
    std::cerr << "RenderInterface::LoadTexture" << std::endl;
    
    window_->setActive();

    Rocket::Core::FileInterface* file_interface = Rocket::Core::GetFileInterface();
    Rocket::Core::FileHandle file_handle = file_interface->Open(source);
    if (file_handle == NULL)
        return false;

    file_interface->Seek(file_handle, 0, SEEK_END);
    size_t buffer_size = file_interface->Tell(file_handle);
    file_interface->Seek(file_handle, 0, SEEK_SET);
    
    char* buffer = new char[buffer_size];
    file_interface->Read(buffer, buffer_size, file_handle);
    file_interface->Close(file_handle);

    sf::Texture *image = new sf::Texture();

    if(!image->loadFromMemory(buffer, buffer_size))
    {
        delete buffer;
        delete image;

        return false;
    };
    delete buffer;

    texture_handle = reinterpret_cast<Rocket::Core::TextureHandle>(image);
    texture_dimensions = Rocket::Core::Vector2i(image->getWidth(), image->getHeight());

    return true;
}

// Called by Rocket when a texture is required to be built from an internally-generated sequence of pixels.
bool RenderInterface::GenerateTexture(Rocket::Core::TextureHandle& texture_handle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& source_dimensions)
{
    std::cerr << "RenderInterface::GenerateTexture" << std::endl;
    
    window_->setActive();

    sf::Texture *image = new sf::Texture();
    
    sf::Texture *texture = new sf::Texture();
    if (!texture->create(source_dimensions.x, source_dimensions.y)) 
    {
        delete texture;
        return false;
    }
    texture->update(source, source_dimensions.x, source_dimensions.y, 0, 0);
    texture_handle = reinterpret_cast<Rocket::Core::TextureHandle>(image);

    return true;
}

// Called by Rocket when a loaded texture is no longer required.        
void RenderInterface::ReleaseTexture(Rocket::Core::TextureHandle texture_handle)
{
    window_->setActive();

    delete reinterpret_cast<sf::Texture*>(texture_handle);
}
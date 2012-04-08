
#include "RenderInterface.h"

#include <Rocket/Core/Core.h>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

using namespace spaceg;



//shader
static const char* vertexShader =
"\
void main(void) \
{ \
    gl_Position = gl_Vertex; \
}";


static const char* fragmentShader = 
" \
void main(void) \
{ \
    gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0); \
}";

//gl_FragColor = texture2D( s_texture, v_texCoord ) * v_color;

RenderInterface::RenderInterface(sf::RenderTarget* Window)
{
    target_ = Window;
    this->resize();
}


void RenderInterface::startRender()
{
    target_->pushGLStates();
    
    // set required blend states
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //sf::BlendMode
}

void RenderInterface::finishRender()
{
    glDisable(GL_BLEND);
    target_->popGLStates();
}

void RenderInterface::resize()
{
    /*
    auto wsize = target_->getSize();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, wsize.x, wsize.y, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glViewport(0, 0, wsize.x, wsize.y);
    */
};

// Called by Rocket when it wants to render geometry that it does not wish to optimise.
void RenderInterface::RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, const Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation)
{
    //std::cerr << "RenderInterface::RenderGeometry" << std::endl;
    //std::cerr << "num_vertices: " <<  num_vertices << " num_indices: " << num_indices << std::endl;
    
    
    //render state blend and transform
    sf::RenderStates state;
    state.transform.translate(translation.x, translation.y);
    //state.blendMode = sf::BlendAlpha;
    state.texture = reinterpret_cast<sf::Texture*>(texture);    
    
    //setup shader
    auto shader = new sf::Shader();
    shader->loadFromMemory(vertexShader, sf::Shader::Vertex);
    shader->loadFromMemory(fragmentShader, sf::Shader::Fragment);
    //state.shader = shader;
    //requires special shader?
    
    sf::VertexArray triangles(sf::TrianglesStrip, num_indices);
    
    for(int i=0; i < num_indices; i++)
    {
        auto vert = vertices[indices[i]];
        
        triangles[i].position = sf::Vector2f(vert.position.x, vert.position.y);
        triangles[i].texCoords = sf::Vector2f(vert.tex_coord.x, vert.tex_coord.y);
        triangles[i].color = sf::Color(vert.colour.red, vert.colour.green, vert.colour.blue, vert.colour.alpha);
    }
    
    target_->draw(triangles, state);
}

// Called by Rocket when it wants to compile geometry it believes will be static for the forseeable future.     
Rocket::Core::CompiledGeometryHandle RenderInterface::CompileGeometry(Rocket::Core::Vertex* vertices,
                                                                           int num_vertices, int* indices,
                                                                           int num_indices,
                                                                           const Rocket::Core::TextureHandle texture)
{
    std::cerr << "RenderInterface::CompileGeometry" << std::endl;
    
    
    return (Rocket::Core::CompiledGeometryHandle)NULL;
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
    std::cerr << "RenderInterface::LoadTexture: " << source.CString() << std::endl;
    
    /*
    Rocket::Core::FileInterface* file_interface = Rocket::Core::GetFileInterface();
    Rocket::Core::FileHandle file_handle = file_interface->Open(source);
    if (file_handle == (Rocket::Core::FileHandle)NULL)
        return false;

    file_interface->Seek(file_handle, 0, SEEK_END);
    size_t buffer_size = file_interface->Tell(file_handle);
    file_interface->Seek(file_handle, 0, SEEK_SET);
    
    char* buffer = new char[buffer_size];
    file_interface->Read(buffer, buffer_size, file_handle);
    file_interface->Close(file_handle);
    */
    
    sf::Texture *image = new sf::Texture();

    if(!image->loadFromFile(source.CString()))
    {
        //delete buffer;
        delete image;

        return false;
    };
    //delete buffer;
    
    std::cerr << image->getWidth() << ", " << image->getHeight() << std::endl;

    texture_handle = reinterpret_cast<Rocket::Core::TextureHandle>(image);
    texture_dimensions = Rocket::Core::Vector2i(image->getWidth(), image->getHeight());

    return true;
}

// Called by Rocket when a texture is required to be built from an internally-generated sequence of pixels.
bool RenderInterface::GenerateTexture(Rocket::Core::TextureHandle& texture_handle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& source_dimensions)
{
    std::cerr << "RenderInterface::GenerateTexture" << std::endl;
    
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
    delete reinterpret_cast<sf::Texture*>(texture_handle);
}
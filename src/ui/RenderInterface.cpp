


#include "RenderInterface.h"


#include <Rocket/Core.h>

#include <GL/glew.h>

#include <SFML/Graphics/Texture.hpp>

#define GL_CLAMP_TO_EDGE 0x812F

using namespace spaceg;

class RenderInterfaceGeometryHandler 
{
public:
    GLuint VertexID, IndexID;
    int NumVertices;
    Rocket::Core::TextureHandle Texture;

    RenderInterfaceGeometryHandler() : VertexID(0), IndexID(0), Texture(0), NumVertices(0) { }

    ~RenderInterfaceGeometryHandler() 
    {
        if(VertexID)
            glDeleteBuffers(1, &VertexID);

        if(IndexID)
            glDeleteBuffers(1, &IndexID);

        VertexID = IndexID = 0;
    };
};

struct RenderInterfaceVertex 
{
    sf::Vector2f Position, TexCoord;
    sf::Color Color;
};


RenderInterface::RenderInterface(boost::shared_ptr<sf::RenderWindow> window) : m_window(window) 
{
    resize();
}

void RenderInterface::prepare() 
{
    m_window->setView(m_window->getDefaultView());
}


void RenderInterface::resize() 
{
    m_window->setActive(true);
    
    auto wsize = m_window->getSize();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, wsize.x, wsize.y, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    glViewport(0, 0, wsize.x, wsize.y);
};

// Called by Rocket when it wants to render geometry that it does not wish to optimize.
void RenderInterface::RenderGeometry(Rocket::Core::Vertex* vertices, int num_vertices, int* indices, int num_indices, const Rocket::Core::TextureHandle texture, const Rocket::Core::Vector2f& translation)
{
    m_window->setActive();

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

    if(sfTexture) {
        sfTexture->bind();
    } else {
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
    m_window->setActive();

    /*
    if(!GLEE_VERSION_2_0)
        return (Rocket::Core::CompiledGeometryHandle) NULL;
    */

    std::vector<RenderInterfaceVertex> Data(num_vertices);

    for(unsigned long i = 0; i < Data.size(); i++)
    {
        Data[i].Position = *(sf::Vector2f*)&vertices[i].position;
        Data[i].TexCoord = *(sf::Vector2f*)&vertices[i].tex_coord;
        Data[i].Color = sf::Color(vertices[i].colour.red, vertices[i].colour.green,
            vertices[i].colour.blue, vertices[i].colour.alpha);
    };

    RenderInterfaceGeometryHandler *Geometry = new RenderInterfaceGeometryHandler();
    Geometry->NumVertices = num_indices;

    glGenBuffers(1, &Geometry->VertexID);
    glBindBuffer(GL_ARRAY_BUFFER, Geometry->VertexID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(RenderInterfaceVertex) * num_vertices, &Data[0],
        GL_STATIC_DRAW);

    glGenBuffers(1, &Geometry->IndexID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Geometry->IndexID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * num_indices, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    Geometry->Texture = texture;

    return (Rocket::Core::CompiledGeometryHandle)Geometry;
}

// Called by Rocket when it wants to render application-compiled geometry.
void RenderInterface::RenderCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry, const Rocket::Core::Vector2f& translation)
{
    m_window->setActive();

    RenderInterfaceGeometryHandler *RealGeometry = (RenderInterfaceGeometryHandler *)geometry;

    glPushMatrix();
    glTranslatef(translation.x, translation.y, 0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    sf::Texture *texture = (sf::Texture *)RealGeometry->Texture;

    if(texture) {
        texture->bind();
    } else {
        glBindTexture(GL_TEXTURE_2D, 0);
    };

    glEnable(GL_VERTEX_ARRAY);
    glEnable(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_COLOR_ARRAY);

#define BUFFER_OFFSET(x) ((char*)0 + x)

    glBindBuffer(GL_ARRAY_BUFFER, RealGeometry->VertexID);
    glVertexPointer(2, GL_FLOAT, sizeof(RenderInterfaceVertex), BUFFER_OFFSET(0));
    glTexCoordPointer(2, GL_FLOAT, sizeof(RenderInterfaceVertex), BUFFER_OFFSET(sizeof(sf::Vector2f)));
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(RenderInterfaceVertex), BUFFER_OFFSET(sizeof(sf::Vector2f[2])));

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, RealGeometry->IndexID);
    glDrawElements(GL_TRIANGLES, RealGeometry->NumVertices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDisable(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_VERTEX_ARRAY);

    glColor4f(1, 1, 1, 1);

    glPopMatrix();
}

// Called by Rocket when it wants to release application-compiled geometry.
void RenderInterface::ReleaseCompiledGeometry(Rocket::Core::CompiledGeometryHandle geometry) 
{
    m_window->setActive();
    delete (RenderInterfaceGeometryHandler *)geometry;
}

// Called by Rocket when it wants to enable or disable scissoring to clip content.
void RenderInterface::EnableScissorRegion(bool enable) 
{
    m_window->setActive();
    if (enable)
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);
}

// Called by Rocket when it wants to change the scissor region.
void RenderInterface::SetScissorRegion(int x, int y, int width, int height) 
{
    m_window->setActive();
    glScissor(x, m_window->getSize().y - (y + height), width, height);
}

// Called by Rocket when a texture is required by the library.
bool RenderInterface::LoadTexture(Rocket::Core::TextureHandle& texture_handle, Rocket::Core::Vector2i& texture_dimensions, const Rocket::Core::String& source) {
    m_window->setActive();

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

    sf::Texture *texture = new sf::Texture();

    if(!texture->loadFromMemory(buffer, buffer_size)) {
        delete buffer;
        delete texture;
        return false;
    };
    delete buffer;

    texture_handle = (Rocket::Core::TextureHandle) texture;
    texture_dimensions = Rocket::Core::Vector2i(texture->getWidth(), texture->getHeight());

    return true;
}

// Called by Rocket when a texture is required to be built from an internally-generated sequence of pixels.
bool RenderInterface::GenerateTexture(Rocket::Core::TextureHandle& texture_handle, const Rocket::Core::byte* source, const Rocket::Core::Vector2i& source_dimensions) {
    m_window->setActive();
    sf::Texture *texture = new sf::Texture();
    if (!texture->create(source_dimensions.x, source_dimensions.y)) {
        delete texture;
        return false;
    }
    texture->update(source, source_dimensions.x, source_dimensions.y, 0, 0);
    texture_handle = (Rocket::Core::TextureHandle)texture;
    return true;
}

// Called by Rocket when a loaded texture is no longer required.
void RenderInterface::ReleaseTexture(Rocket::Core::TextureHandle texture_handle) {
    m_window->setActive();
    delete (sf::Texture *)texture_handle;
}
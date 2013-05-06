
#include "SfmlSprite.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "../Log.hpp"

using namespace spaceg;
using namespace sf;


SfmlSprite::SfmlSprite()
	: texture_(nullptr)
{
	const float corner = 256.f;
	vertices_[0].position = Vector2f(0, 0);
    vertices_[1].position = Vector2f(0, corner);
    vertices_[2].position = Vector2f(corner, corner);
    vertices_[3].position = Vector2f(corner, 0);
}

SfmlSprite::~SfmlSprite()
{
}


void SfmlSprite::setTexture(const Texture& texture)
{
	texture_ = &texture;
	auto size = texture.getSize();
	setTextureRect(sf::FloatRect(0.f, 0.f, size.x, size.y));
}

void SfmlSprite::setColor(const Color& color)
{
	 // Update the vertices' color
    vertices_[0].color = color;
    vertices_[1].color = color;
    vertices_[2].color = color;
    vertices_[3].color = color;
}

void SfmlSprite::setSize(float width, float height)
{
	//calculate scale
	auto lbounds = getLocalBounds();
	
	//cul::Log::Source().verbose("[SfmlSprite::setSize] lbound: %f, %f, %f, %f", lbounds.left, lbounds.top, lbounds.width, lbounds.height);
	float xscale = width/lbounds.width;
	float yscale = height/lbounds.height;
	//cul::Log::Source().verbose("[SfmlSprite::setSize] param: %f, %f", width, height);
	//cul::Log::Source().verbose("[SfmlSprite::setSize] scale: %f, %f", xscale, yscale);
	setScale(xscale, yscale);
}


void SfmlSprite::setTextureRect(const sf::FloatRect& rect)
{ 
	float left = rect.left;
    float right = left + rect.width;
    float top = rect.top;
    float bottom = top + rect.height;
   
	//cul::Log::Source().verbose("[SfmlSprite::setTextureRect] rect: %f, %f, %f, %f", rect.left, rect.top, rect.width, rect.height);
	
    vertices_[0].texCoords = Vector2f(left, top);
    vertices_[1].texCoords = Vector2f(left, bottom);
    vertices_[2].texCoords = Vector2f(right, bottom);
    vertices_[3].texCoords = Vector2f(right, top); 
}

sf::FloatRect SfmlSprite::getTextureRect() const
{
	return FloatRect(vertices_[0].texCoords.x, 
					 vertices_[0].texCoords.y, 
	                 vertices_[2].texCoords.x-vertices_[0].texCoords.x, 
	                 vertices_[2].texCoords.y-vertices_[0].texCoords.y);
}

FloatRect SfmlSprite::getLocalBounds() const
{
	auto topleft = vertices_[0].position;
	auto bottomright = vertices_[2].position;

    return FloatRect(topleft.x, topleft.y, bottomright.x-topleft.x, bottomright.y-topleft.y);
}

FloatRect SfmlSprite::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void SfmlSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (texture_)
    {
        states.transform *= getTransform();
        states.texture = texture_;
        target.draw(vertices_, 4, sf::Quads, states);
    }
}

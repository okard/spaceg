
#pragma once
#ifndef __SPACEG_SFMLSPRITE__
#define __SPACEG_SFMLSPRITE__

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>


namespace spaceg {
	
/**
* An advanced sfml sprite
* Fix the broken api of sf::Sprite
*/
class SfmlSprite : public sf::Drawable, public sf::Transformable
{
private:
	sf::Vertex vertices_[4];
	const sf::Texture* texture_;
	//Shader

public:
	SfmlSprite();
	~SfmlSprite();
	
	void setTexture(const sf::Texture& texture);
	void setColor(const sf::Color& color);
	void setSize(float width, float height);
	void setTextureRect(const sf::FloatRect& rect);
	
	inline const sf::Texture* getTexture() const { return texture_; }
	const sf::Color& getColor() const  { return vertices_[0].color; }
	sf::FloatRect getTextureRect() const;
	
	sf::FloatRect getLocalBounds() const;
	sf::FloatRect getGlobalBounds() const;


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	//setPosition()
	//getPosition()
	//setSize()
	//getSize()
};
	
} // end namespace spaceg



#endif


#include "MainMenu.h"

#include<SFML/Graphics.hpp>

#include "../Application.h"


using namespace spaceg;

MainMenu::MainMenu(Application* const app)
    : app_(app)
{
    
}

MainMenu::~MainMenu()
{
    
}

//update
void MainMenu::update(long timeElapsed)
{
    
}
    
//draw
void MainMenu::draw()
{
    auto ctx = app_->getRenderTexture();
    sf::RectangleShape rect(sf::Vector2f(50, 50));
    rect.setPosition(sf::Vector2f(50, 50));
    
    ctx->draw(rect);
    
}
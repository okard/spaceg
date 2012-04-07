
#include "Application.h"

#include <boost/shared_ptr.hpp>


#include "ui/SystemInterface.h"
#include "ui/RenderInterface.h"

using namespace spaceg;

Application::Application()
    : window_(sf::VideoMode(800, 600), "SpaceG"),
      mainMenu_(this)
{
    window_.setFramerateLimit(60);
    
    auto size = window_.getSize();
    
    renderTexture_.create(size.x, size.y);
    
    boost::shared_ptr<sf::RenderWindow> p(&window_);
    Rocket::Core::SetRenderInterface(new RenderInterface(p));
    Rocket::Core::SetSystemInterface(new SystemInterface());
    
    Rocket::Core::Initialise();
    
    currentState_ = &mainMenu_;
}

Application::~Application()
{
    
}

void Application::run()
{
     // Start the game loop
     while (window_.isOpen())
     {
        // Process events
        sf::Event event;
        while (window_.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window_.close();
        }
         
        // Clear the whole texture with red color
        renderTexture_.clear(sf::Color::Black);

        // Draw stuff to the texture
        currentState_->draw();

        // We're done drawing to the texture
        renderTexture_.display();
        
        // Clear screen
        window_.clear();
         
        //Draw Render Texture
        renderSprite_.setTexture(renderTexture_.getTexture());
        window_.draw(renderSprite_);
 
        // Update the window
        window_.display();
     }
    
}


sf::RenderTexture* const Application::getRenderTexture()
{
    return &renderTexture_;
}
     
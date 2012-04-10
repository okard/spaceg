
#include "Application.h"

#include <GL/glew.h>

#include "ui/RenderInterface.h"
#include "ui/SfmlUtils.h"

using namespace spaceg;

Application::Application()
    : window_(sf::VideoMode(800, 600), "SpaceG"),
      mainMenu_(this)
{
    //setting up sfml render stuff
    window_.setFramerateLimit(60);
    auto size = window_.getSize();
    renderTexture_.create(size.x, size.y);
    
    //glew init
    glewInit();
    
    //GUI Init
    uiRenderInterface_ = new RenderInterface(&window_);
    Rocket::Core::SetRenderInterface(uiRenderInterface_);
    Rocket::Core::SetSystemInterface(&uiSysInterface_);
    Rocket::Core::Initialise();
    
    uiCtx_ = Rocket::Core::CreateContext("default", Rocket::Core::Vector2i(size.x, size.y));
    
    //test
    Rocket::Core::FontDatabase::LoadFontFace("data/fonts/LinLibertine_R.otf", "Libertine", Rocket::Core::Font::STYLE_NORMAL, Rocket::Core::Font::WEIGHT_NORMAL);
    Rocket::Core::FontDatabase::LoadFontFace("data/fonts/Delicious-Bold.otf");
    Rocket::Core::ElementDocument* document = uiCtx_->LoadDocument("data/ui_test.rml");
    if (document != NULL)
        document->Show();
    
    
    //State Stuff
    currentState_ = &mainMenu_;
}

Application::~Application()
{
    uiCtx_->RemoveReference();
    delete uiRenderInterface_;
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
           handleEvent(event);
        }
        
        uiCtx_->Update();
         
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
        //Post Effects Fragment shader
        
        uiRenderInterface_->startRender();
        uiCtx_->Render();
        uiRenderInterface_->finishRender();
 
        // Update the window
        window_.display();
     }
    
}

void Application::handleEvent(const sf::Event& event)
{
     //TODO Switch case
            
    // Close window : exit
    if (event.type == sf::Event::Closed)
        window_.close();
    
    // The window was resized
    if (event.type == sf::Event::Resized)
        uiCtx_->SetDimensions(Rocket::Core::Vector2i(event.size.width, event.size.height));
    
    //TODO key_modifier Keyboard and CTRL/ALT/...
    
    if(event.type == sf::Event::MouseMoved)
        uiCtx_->ProcessMouseMove(event.mouseMove.x, event.mouseMove.y, 0);
    
    if(event.type == sf::Event::MouseButtonPressed)
        uiCtx_->ProcessMouseButtonDown(mouseButtonConvert(event.mouseButton.button), 0);
        
    if(event.type == sf::Event::MouseButtonReleased)
        uiCtx_->ProcessMouseButtonUp(mouseButtonConvert(event.mouseButton.button), 0);
    
    if(event.type == sf::Event::MouseWheelMoved)
        uiCtx_->ProcessMouseWheel(event.mouseWheel.delta, 0);
        
    if(event.type == sf::Event::KeyPressed)
        uiCtx_->ProcessKeyDown(keyConvert(event.key.code), 0);
    
    if(event.type == sf::Event::KeyReleased)
        uiCtx_->ProcessKeyUp(keyConvert(event.key.code), 0);
    
    // Sends a single character of text as text input into this context.
    //void ProcessTextInput(Rocket::Core::word character);
    // Sends a string of text as text input into this context.
    //void ProcessTextInput(const Rocket::Core::String& string);
}


sf::RenderTexture* const Application::getRenderTexture()
{
    return &renderTexture_;
}
     
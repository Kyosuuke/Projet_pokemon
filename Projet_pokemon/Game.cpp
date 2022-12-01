#include "Game.h"


Game::Game() {
    this->initVariables();
   this->gameInit();
    this->gameLoop();
}

void Game::initVariables() {
    
    this->window = nullptr;
    //class
    
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon ");
}


void Game::gameLoop() {

    sf::Texture playerTexture;
    playerTexture.loadFromFile(PLAYER_TEXTURE_PATH);
    Player player(&playerTexture, sf::Vector2u(4, 4), 0.3f, 100.0f);
    
    float deltaTime = 0.0f;
    sf::Clock clock;
        
            while (this->window->isOpen())
            {
                window->clear();

                while (this->window->pollEvent(this->event))
                {
                    
                    
                    


                    if (this->event.type == sf::Event::Closed)
                        this->window->close();

                }

                player.Draw(window);

                player.Update(deltaTime);
                deltaTime = clock.restart().asSeconds();

                window->display();
                
            }
}

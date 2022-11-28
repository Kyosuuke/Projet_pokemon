#include "Game.h"


Game::Game() {

    initVariables();
    gameInit();
    this->menu;
    gameLoop();
}

void Game::initVariables() {
    
    this->window = nullptr;

    //class
    this->menu = new Menu;
    
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pokemon NON Edition");
}

// void Game::gameRender(){

// }

void Game::gameLoop() {

    sf::Texture playerTexture;
    playerTexture.loadFromFile(PLAYER_TEXTURE_PATH);
    Player player(&playerTexture, sf::Vector2u(4, 4), 0.3f, 100.0f);
    
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (this->window->isOpen())
    {

        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();
        }

        player.Update(deltaTime);
        deltaTime = clock.restart().asSeconds();
        
        window->clear();
        //this->menu->render(this->window);
        
        player.Draw(window);


        window->display();

    }
}
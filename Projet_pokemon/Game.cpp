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

    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pokemon NON Edition");
}

void Game::gameLoop() {

    // Texture
    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    sf::Texture npcTexture;
    npcTexture.loadFromFile(NPC_TEXTURE_PATH, sf::IntRect(36,0,30,64));
    Npcs npcs(&npcTexture);
    sf::Texture playerTexture;
    playerTexture.loadFromFile(PLAYER_TEXTURE_PATH);
    Player player(&playerTexture, sf::Vector2u(3, 4), 0.2f, 100.0f);

    // Deltatime
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (this->window->isOpen())
    {
        window->clear();
        this->menu->render(this->window);
        this->menu;
        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();
        }

        player.Update(deltaTime);
        deltaTime = clock.restart().asSeconds();
        
        window->clear();
        this->menu->render(this->window);
        
        //player.Draw(window);


        window->display();

    }
}
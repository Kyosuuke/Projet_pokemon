#include "Game.h"

Game::Game() {

    initVariables();
    gameInit();
    gameLoop();
}

void Game::initVariables() {
    
    this->window = nullptr;

    //class
    this->menu = new Menu;
    
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pokemon NON Edition");
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

    // Collision
    sf::FloatRect nextPos;

    while (this->window->isOpen())
    {
        window->clear();
        this->menu->render(this->window);
        this->menu;
        while (this->window->pollEvent(this->event))
        {

            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::Resized:
                break;
            
            }
        }

        deltaTime = clock.restart().asSeconds();
        player.Update(deltaTime);

        // Window with the player at the center 
        view.setCenter(player.GetPosition());
        window->setView(view);
        window->clear();
        //this->menu->render(this->window);
        player.Draw(window);
        npcs.Draw(window);
        window->display();
    }
}
#include "Game.h"

Game::Game() {
    this->initVariables();
    this->gameInit();
    this->gameLoop();
}

void Game::initVariables() {
    
    this->window = nullptr;
    this->fields = new Fields();
    //class
    
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon NON Edition");
    this->fields->grass();
}

void Game::gameLoop() {

    // Texture
    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));
    sf::Texture npcTexture;
    npcTexture.loadFromFile(NPC_TEXTURE_PATH, sf::IntRect(32,0,32,48));
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
        
        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();

            if (this->event.type == sf::Event::KeyPressed) {
                if (this->event.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
            }
        }

        // Player movement
        player.Update(deltaTime);
        deltaTime = clock.restart().asSeconds();
        
        // View
        view.setCenter(player.GetPosition());
        view.setSize(1980, 1080);
        view.zoom(0.475f);
        window->setView(view);

        window->clear();

        this->fields->grassMap(*this->window);
        this->fields->dirtMap(*this->window);

        
        // Rendering the player
        player.Draw(window);

        // Rendering the npc
        npcs.Draw(window);

        window->display();

    }
}
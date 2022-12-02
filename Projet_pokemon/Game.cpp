#include "Game.h"



Game::Game() {
    this->initVariables();
    this->gameInit();
    this->gameLoop();
}

void Game::initVariables() {
    
    this->window = nullptr;
    this->fields = new Fields();
    this->battle = new Battle();
    //class
    
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon NON Edition");
    this->fields->grass();
    this->battle->textureBattle();
}

void Game::gameLoop() {

    // View
    sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(VIEW_WITDH, VIEW_HEIGHT));

    // Texture
    sf::Texture npcTexture;
    npcTexture.loadFromFile(NPC_TEXTURE_PATH, sf::IntRect(32,0,32,48));
    Npcs npcs(&npcTexture);
    sf::Texture playerTexture;
    playerTexture.loadFromFile(PLAYER_TEXTURE_PATH);
    Player player(&playerTexture, sf::Vector2u(3, 4), 0.2f, 16.0f);

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

            if (this->event.type == sf::Event::KeyPressed) {
                if (this->event.key.code == sf::Keyboard::A) {
                    end = true;
                    while (end == true)
                    {
                        this->window->clear();
                        this->battle->changeWindow(*this->window);
                        this->window->display();
                        //view.reset(player.GetPosition());
                        //view.setCenter(this->battle->bgBattle.getPosition());
                    }
                }
            }
        }

        // Player movement
        player.Update(deltaTime);
        deltaTime = clock.restart().asSeconds();
        
        // View
        view.setCenter(player.GetPosition());
        this->window->setView(view);

        this->window->clear();

        // Rendering the map
        this->fields->grassMap(*this->window);
        this->fields->dirtMap(*this->window);

        
        // Rendering the player
        player.Draw(window);

        // Rendering the npc
        npcs.Draw(window);

        window->display();

    }
}
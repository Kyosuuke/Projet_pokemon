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

        player.Update(deltaTime);
        deltaTime = clock.restart().asSeconds();
        
        view.setCenter(player.GetPosition());
        this->window->setView(view);

        this->window->clear();

        this->fields->grassMap(*this->window);
        this->fields->dirtMap(*this->window);

        player.Draw(window);

        npcs.Draw(window);

        window->display();

    }
}
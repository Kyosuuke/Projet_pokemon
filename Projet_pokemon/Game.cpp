#include "Game.h"
#include "Player.h"
#include "Animation.h"

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
    this->player = new Player;
   
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pokemon NON Edition");
}

// void Game::gameRender(){

// }

void Game::gameLoop() {

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
        render();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            this->player->move(-1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            this->player->move(1.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            this->player->move(0.f, -1.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            this->player->move(0.f, 1.f);
    }
}

void Game::initPlayer()
{
    this->player = new Player;
}

void Game::render()
{
    this->window->clear();

    this->player->render(this->window);

    this->window->display();
}
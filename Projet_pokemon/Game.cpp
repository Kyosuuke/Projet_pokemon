#include "Game.h"

Game::Game() {
    initVariables();
    gameInit();
    this->initPlayer();
    gameLoop();
}

void Game::initVariables() {
    this->window = nullptr;
}

void Game::gameInit() {


    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Pokemon");
    this->shape.setRadius(100.f);
    this->shape.setFillColor(sf::Color::Green);
}

// void Game::gameRender(){

// }

void Game::gameLoop() {

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
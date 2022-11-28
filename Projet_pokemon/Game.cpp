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
    this->player = new Player;
   
}

void Game::gameInit() {

    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Pokemon NON Edition");
}

void Game::gameLoop() {

    while (this->window->isOpen())
    {
        

        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed)
                this->window->close();
        }
        render();

        this->player;
        //keyboard part
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


void Game::render()
{
    this->window->clear();

    this->menu->render(this->window);
    this->player->render(this->window);

    this->window->display();
}
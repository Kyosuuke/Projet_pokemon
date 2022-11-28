#pragma once
#include "General.h"
#include "Player.h"
#include <chrono>

class Game {

public:

    //COnstructuor
    Game();

    //Functions
    //void gameRender();

    void gameLoop();

private:
    // Variables
        // window
    sf::RenderWindow* window;
    // shape
    sf::CircleShape shape;
    // Event
    sf::Event event;

    // functions
    void initVariables();
    void gameInit();
};
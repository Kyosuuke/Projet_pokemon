#pragma once
#include "General.h"
#include "Player.h"


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

    // Player
    Player* player;

    // functions
    void render();
    void initVariables();
    void gameInit();
    void initPlayer();
};
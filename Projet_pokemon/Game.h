#pragma once
#include "General.h"
#include "Player.h"
#include "Menu.h"

class Game {

public:

    //Constructuor
    Game();

    //Functions
    

    void gameLoop();

private:
    // Variables
    // window
    sf::RenderWindow* window;

    // Event
    sf::Event event;

    // Player
    Player* player;

    // functions
    void initVariables();
    void gameInit();
    void initPlayer();
};
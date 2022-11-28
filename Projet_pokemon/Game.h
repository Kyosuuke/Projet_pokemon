#pragma once
#include "General.h"
#include "Player.h"
#include "Menu.h"
#include "Animation.h"

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

    //Menu
    Menu* menu;

    // functions
    void initVariables();
    void gameInit();
};
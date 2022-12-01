#pragma once
#include "General.h"
#include "Player.h"
#include "Animation.h"

class Game {

public:

    //Constructuor
    Game();

    //Functions
    
    void initVariables();
    void gameInit();
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

    // functions
    
    
};
#pragma once
#include "General.h"
#include "Player.h"
#include "Animation.h"
#include "Npcs.h"

static const float VIEW_HEIGHT = 1080;
static const float VIEW_WITDH = 1920;

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

    // Npcs
    Npcs* npcs;
    std::vector<sf::RectangleShape> Rect;

    // Player
    Player* player;
    //Menu

    // functions
    
    
};
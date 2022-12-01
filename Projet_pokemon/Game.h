#pragma once
#include "General.h"
#include "Player.h"
#include "Animation.h"
#include "Npcs.h"
#include "Fields.h"

static const float VIEW_HEIGHT = 600;
static const float VIEW_WITDH = 700;

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
    
    // Map
    Fields* fields;

    // Player
    Player* player;

    // functions
    
    
};
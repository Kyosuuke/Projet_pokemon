#pragma once
#include "General.h"
#include "Battle.h"
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
    bool end = false;
 // Variables
    // window
    sf::RenderWindow* window;
    // Event
    sf::Event event;

    // Npcs
    Npcs* npcs;
    std::vector<sf::RectangleShape> Rect;

    Fields* fields;

    Battle* battle;
    // Player
    Player* player;
    //Menu

    // functions
    
    
};
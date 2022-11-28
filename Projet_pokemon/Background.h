#pragma once
#include "General.h"

class Background {

public:

    Background();

    void loadBackground();
    void loadSprite();
    void renderSprite(sf::RenderWindow* window);

protected:



private:
    sf::Texture texture;
    sf::Sprite sprite;
};
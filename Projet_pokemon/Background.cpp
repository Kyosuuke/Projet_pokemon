#include "Background.h"

Background::Background() {
    this->loadBackground();
    this->loadSprite();
}

void Background::loadBackground() {

    if (!this->texture.loadFromFile("", sf::IntRect(10, 10, 32, 32)))
    {
        std::cout << "error";
    }

}

void Background::loadSprite() {
    this->sprite.setTexture(this->texture);
}

void Background::renderSprite(sf::RenderWindow* window){
    window->draw(this->sprite);

}
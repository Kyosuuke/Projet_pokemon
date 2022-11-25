#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	float movementSpeed;

	// Private Functions
	void initPlayer();
	void initSprite();

public:
	// Constructor
	Player();

	// Destructor
	~Player();

	// Functions
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderWindow* target);
};
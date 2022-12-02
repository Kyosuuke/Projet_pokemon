#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Models.h"
#include "Animation.h"
#include "Npcs.h"

class Player
{
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

public:
	// Constructor
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	// Destructor
	~Player();

	// Functions
	void Update(float deltaTime);
	void Draw(sf::RenderTarget* target);
	sf::Vector2f GetPosition() { return body.getPosition(); }

	sf::FloatRect nextPos;
	const float gridSize = 50.0f;
	
};
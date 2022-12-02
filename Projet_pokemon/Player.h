#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Models.h"
#include "Animation.h"
#include "Npcs.h"
#include "Fields.h"


class Player
{
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	float x, y;
	int gridX, gridY;

public:
	// Constructor
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	// Destructor
	~Player();

	const float gridSize = 16.0f;

	Fields* fields;
	
	// Functions
	void Update(float deltaTime);
	void Draw(sf::RenderTarget* target);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::FloatRect oldPos;
	sf::FloatRect nextPos;
	
};
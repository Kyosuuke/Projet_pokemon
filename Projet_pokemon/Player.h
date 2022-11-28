#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Model.h"
#include "Animation.h"

class Player
{
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	bool faceUp;

public:
	// Constructor
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);

	// Destructor
	~Player();

	// Functions
	void Update(float deltaTime);
	void Draw(sf::RenderTarget* target);
	
};
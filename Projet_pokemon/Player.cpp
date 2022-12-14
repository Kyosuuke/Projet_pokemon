#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	const float gridSize = 16.0f;
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(36.f, 48.f));
	body.setOrigin(body.getSize() / 2.f);
	body.setPosition(sf::Vector2f(gridSize, gridSize));
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	oldPos = body.getGlobalBounds();
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= speed;
		row = 1;
		animation.Update(row, deltaTime, faceRight);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += speed;
		row = 2;
		animation.Update(row, deltaTime, faceRight);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= speed;
		row = 3;
		animation.Update(row, deltaTime, faceRight);
	}	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += speed;
		row = 0;
		animation.Update(row, deltaTime, faceRight);
	}

	std::cout << GetPosition().x << std::endl;
	std::cout << GetPosition().y << std::endl;
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderTarget* target)
{
	target->draw(this->body);
}



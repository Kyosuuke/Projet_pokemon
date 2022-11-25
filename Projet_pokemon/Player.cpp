#include "Player.h"

Player::Player()
{
	this->movementSpeed = 1.f;

	this->initPlayer();
	this->initSprite();
}

Player::~Player()
{

}

void Player::initPlayer()
{
	if(!this->texture.loadFromFile("Assets/Groudon.png", sf::IntRect(100,0,100,100)))
	{
		std::cout << "Error";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(1.f, 1.f);
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{

}

void Player::render(sf::RenderWindow* target)
{
	target->draw(this->sprite);
}
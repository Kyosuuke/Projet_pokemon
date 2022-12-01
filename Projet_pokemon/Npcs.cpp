#include "Npcs.h"

Npcs::Npcs(sf::Texture* texture)
{
	const float gridSize = 50.0f;
	std::vector<sf::RectangleShape> Rect;
	
	rect.setSize(sf::Vector2f(gridSize, gridSize));
	rect.setPosition(gridSize * 5, gridSize * 2);
	rect.setTexture(texture);
	
	Rect.push_back(rect);
}

Npcs::~Npcs()
{
}

void Npcs::Draw(sf::RenderTarget* target)
{
	target->draw(this->rect);
}

void Npcs::Update()
{
}

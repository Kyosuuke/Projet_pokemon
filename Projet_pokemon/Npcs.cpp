#include "Npcs.h"

Npcs::Npcs(sf::Texture* texture)
{
	const float gridSize = 16.0f;
	std::vector<sf::RectangleShape> Rect;
	
	rect.setSize(sf::Vector2f(32.f, 48.f));
	rect.setPosition(gridSize * 10, gridSize * 5);
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

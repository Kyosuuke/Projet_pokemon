#pragma once
#include "General.h"

class Npcs
{
public:
	Npcs(sf::Texture* texture);
	~Npcs();

	void Draw(sf::RenderTarget* target);
	void Update();

private:
	sf::RectangleShape rect;
};
#include "Battle.h"


Battle::Battle()
{
	textureBattle();
}
void Battle::textureBattle()
{
	if (!this->bgSet.loadFromFile("Assets/battlePoke.jpg"))
	{
		std::cout << "error";
	}
}

void Battle::changeWindow(sf::RenderWindow& battle)
{	
		this->bgBattle.setTexture(this->bgSet);
		//this->bgBattle.setTextureRect(sf::IntRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
		this->bgBattle.scale(1.f, 1.f);
		this->bgBattle.setOrigin(bgBattle.getTexture()->getSize().x / 2, bgBattle.getTexture()->getSize().y / 2);
		this->bgBattle.setPosition(0, 0);
		battle.draw(this->bgBattle);
}

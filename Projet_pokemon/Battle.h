#include "General.h"


class Battle
{
public:
	Battle();
	void textureBattle();
	void changeWindow(sf::RenderWindow& battle);


	bool poke;
	sf::Sprite bgBattle;
	sf::Texture bgSet;
private:

};

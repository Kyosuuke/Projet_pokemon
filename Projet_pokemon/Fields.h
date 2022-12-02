#pragma once
#include "General.h"
//taille d'un pixel 
const int tileWidth = 16;
const int tileHeight = 16;
//taille de la map
const int mapRow = 68;
const int mapColumn = 120;

class Fields
{

protected:

public:
	
	Fields();
	void grass();
	void dirtMap(sf::RenderWindow& myWallMap);
	void grassMap(sf::RenderWindow& myMap);

private:

	sf::Sprite sprite;
	sf::Sprite wall;
	sf::Texture textureSet;
};
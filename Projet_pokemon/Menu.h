#include "General.h"

class Menu {


public:

	
	Menu();
	
	void render(sf::RenderWindow* targetMenu);

	//function menu part
	void initMenuTexture();

private:
//variables
	//start texture
	sf::Texture startTexture;
	//setting texture
	sf::Texture settingTexture;
	//quit texture
	sf::Texture quitTexture;


	//start sprite
	sf::Sprite startSprite;
	//setting sprite
	sf::Sprite settingSprite;
	//quit srpite
	sf::Sprite quitSprite;

	// text and font
	//text start
	sf::Text textStart;
	//text setting
	sf::Text textSetting;
	//text quit
	sf::Text textQuit;


	sf::Font font;

	//functions 
	//Sprite part
	void initSprite();
	void initFont();
	
};
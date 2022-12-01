#include "General.h"

class Menu {


public:

	
	Menu();
	//~Menu();
	//function menu part

	
	void loopMenu();

	int pos;
	bool isRunning = false;

	// text and font
//text start
	sf::Text textStart;
	//text setting
	sf::Text textSetting;
	//text quit
	sf::Text textQuit;

	sf::Event eventMenu;

	sf::RenderWindow* targetMenu;

protected:
	
	
	sf::Font font;

	
	void initVarMenu();
	void initWindowMenu();
	void initMenuTexture();
	void initFont();
	void render();
	void initMenu();



	//quit srpite
	sf::Sprite titleSprite;

	//quit texture
	sf::Texture titleTexture;
	
};
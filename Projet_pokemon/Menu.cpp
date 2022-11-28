#include "Menu.h"

Menu::Menu() {
	this->initMenuTexture();
	this->initFont();
	this->initSprite();
}

void Menu::initSprite() {
	//start sprite loader
	this->startSprite.setTexture(this->startTexture);

	this->startSprite.scale(0.25f, 0.25f);
	this->startSprite.setPosition(200, 100);

	//setting sprite loader
	this->settingSprite.setTexture(this->settingTexture);

	this->settingSprite.scale(0.25f, 0.25f);
	this->settingSprite.setPosition(250, 150);

	//quit sprite loader
	this->quitSprite.setTexture(this->quitTexture);

	this->quitSprite.scale(0.25f, 0.25f);
	this->quitSprite.setOrigin(200, 200);
	this->textQuit.setString("Quit");
	this->textQuit.move(300, 350);
}

void Menu::initMenuTexture() {
	//Start load

	if (!this->startTexture.loadFromFile("Assets/Menu/Menu.png", sf::IntRect(100, 0, 800, 500)))
	{
		std::cout << "Error";
	}

	//Setting load
	if (!this->settingTexture.loadFromFile("Assets/Menu/Menu.png", sf::IntRect(100, 500, 800, 500)))
	{
		std::cout << "Error";
	}

	//quit load
	if (!this->quitTexture.loadFromFile("Assets/Menu/Menu.png", sf::IntRect(800, 500, 800, 500)))
	{
		std::cout << "Error";
	}
}

void Menu::render(sf::RenderWindow* targetMenu) {

	//sprite part

	// start sprite render
	targetMenu->draw(this->startSprite);

	//setting sprite load
	targetMenu->draw(this->settingSprite);

	//quit sprite load
	targetMenu->draw(this->quitSprite);

	//draw part

	//text start render
	targetMenu->draw(this->textStart);
	//text setting render
	targetMenu->draw(this->textSetting);
	//text quit render
	targetMenu->draw(this->textQuit);
}

void Menu::initFont() {

	if (!font.loadFromFile("WarPriestRegular-PanE.ttf"))
	{
		// error...
	}

	//font for text

	textStart.setFont(font);
	textSetting.setFont(font);
	textQuit.setFont(font);

	//text size

	textStart.setCharacterSize(24);
	textSetting.setCharacterSize(24);
	textQuit.setCharacterSize(24);
}
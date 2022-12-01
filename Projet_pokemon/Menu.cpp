#include "Menu.h"

Menu::Menu() {
    this->initVarMenu();
    this->initWindowMenu();
    this->initMenuTexture();
    this->initFont();
    this->initMenu();
    this->loopMenu();
}

//Menu::~Menu() {
//    delete targetMenu;
//}

void Menu::initVarMenu() {
    this->targetMenu = nullptr;

    pos = 0;
}

void Menu::initWindowMenu() {
    this->targetMenu = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pokemon NON Edition");
}

void Menu::initMenuTexture() {
    //quit load
    if (!this->titleTexture.loadFromFile("Assets/Menu/Title.png"))
    {
        std::cout << "Error";
    }
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

void Menu::initMenu() {

	//setting sprite loader
	this->titleSprite.setTexture(this->titleTexture);

	this->titleSprite.scale(1.f, 1.f);
	this->titleSprite.setOrigin(titleSprite.getTexture()->getSize().x/2, titleSprite.getTexture()->getSize().y / 2);
	this->titleSprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 3);
	

	textStart.setString("Start");
	textStart.setPosition(WINDOW_WIDTH / 2.15, WINDOW_HEIGHT / 1.55);

	textSetting.setString("Setting");
	textSetting.setPosition(WINDOW_WIDTH / 2.15, WINDOW_HEIGHT / 1.35);

	textQuit.setString("Quit");
	textQuit.setPosition(WINDOW_WIDTH / 2.15, WINDOW_HEIGHT / 1.2);
}

void Menu::render() {

    //// start sprite render
    this->targetMenu->draw(this->titleSprite);

    //draw part

    //text start render
    this->targetMenu->draw(this->textStart);
    //text setting render
    this->targetMenu->draw(this->textSetting);
    //text quit render
    this->targetMenu->draw(this->textQuit);
}

void Menu::loopMenu() {
    while (this->targetMenu->isOpen())
    {
        targetMenu->clear();
        render();
        while (this->targetMenu->pollEvent(this->eventMenu))
        {
            if (eventMenu.type == sf::Event::Closed)
                targetMenu->close();
            //key event menu
            if (eventMenu.type == sf::Event::KeyPressed) {

                //key state 1 or < 1
                if (eventMenu.key.code == sf::Keyboard::Down && pos == 0) {

                    pos = 1;
                    //Start is selected
                    textStart.setFillColor(sf::Color::Red);
                    //this->menu->textStart.setOutlineThickness(4);
                    //other is down
                    textSetting.setFillColor(sf::Color::White);
                    textQuit.setFillColor(sf::Color::White);
                }

                else if (eventMenu.key.code == sf::Keyboard::Down && pos == 1) {

                    pos = 2;
                    //Setting is selected
                    textSetting.setFillColor(sf::Color::Red);
                    //this->menu->textStart.setOutlineThickness(4);
                    //other is down
                    textStart.setFillColor(sf::Color::White);
                    textQuit.setFillColor(sf::Color::White);
                }

                else if (eventMenu.key.code == sf::Keyboard::Up && pos <= 1) {

                    pos = 3;
                    //Quit is selected
                    textQuit.setFillColor(sf::Color::Red);
                    //this->menu->textStart.setOutlineThickness(4);
                    //other is down
                    textStart.setFillColor(sf::Color::White);
                    textSetting.setFillColor(sf::Color::White);
                }

                //key state 2

                else if (eventMenu.key.code == sf::Keyboard::Up && pos == 2) {

                    pos = 1;
                    //Start is selected
                    textStart.setFillColor(sf::Color::Red);
                    //other is down
                    textSetting.setFillColor(sf::Color::White);
                    textQuit.setFillColor(sf::Color::White);
                }

                else if (eventMenu.key.code == sf::Keyboard::Down && pos == 2) {


                    pos = 3;
                    //Quit is selected
                    textQuit.setFillColor(sf::Color::Red);
                    //other is down
                    textStart.setFillColor(sf::Color::White);
                    textSetting.setFillColor(sf::Color::White);
                }

                //key state 3

                else if (eventMenu.key.code == sf::Keyboard::Up && pos == 3) {


                    pos = 2;
                    //Setting is selected
                    textSetting.setFillColor(sf::Color::Red);
                    //other is down
                    textStart.setFillColor(sf::Color::White);
                    textQuit.setFillColor(sf::Color::White);
                }

                else if (eventMenu.key.code == sf::Keyboard::Down && pos == 3) {

                    pos = 1;
                    //Start is selected
                    textStart.setFillColor(sf::Color::Red);
                    //other is down
                    textSetting.setFillColor(sf::Color::White);
                    textQuit.setFillColor(sf::Color::White);
                }

                if (eventMenu.key.code == sf::Keyboard::Enter && pos == 1) {
                    this->targetMenu->close();
                    isRunning = true;
                }

                if (this->eventMenu.key.code == sf::Keyboard::Enter && pos == 3) {
                    this->targetMenu->close();
                }
            }
        }
        targetMenu->display();
    }
}







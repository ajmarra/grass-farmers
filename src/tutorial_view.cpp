#include "tutorial_view.h"
#include "master_logic.h"
#include "master_view.h"
#include <iostream>


TutorialView::TutorialView(std::shared_ptr<MasterLogic> &logic,  std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
        this->window = window;

        tutorial_image.spriteMap.loadFromFile("../resources/optionsscreen.png");
        if (!font.loadFromFile("../resources/Amatic-Bold.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    }

void TutorialView::pollInput() {
    sf::Event Event;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = false;

    }

}

void TutorialView::update(float delta){

    this -> pollInput();

    this-> drawScreen();

}

void TutorialView::drawScreen(){
    // this->window->clear(sf::Color::Black);

    //sf::RectangleShape options;
    
    tutorial.setSize(sf::Vector2f(1200, 900));
    tutorial.setTexture(&tutorial_image.spriteMap);
    

    //sf::Text options_message;
    tutorial_message.setFont(font);
    tutorial_message.setString("TUTORIAL");
    tutorial_message.setCharacterSize(100); // in pixels, not points!
    tutorial_message.setFillColor(sf::Color::White);
    tutorial_message.setStyle(sf::Text::Bold);
    tutorial_message.setPosition(470, 20);

    info_message1.setFont(font);
    info_message1.setString(" MOVE UP: W \n MOVE RIGHT: D \n MOVE LEFT: A \n MOVE DOWN: S \n\n PICK UP ITEM: J \n DROP ITEM: K \n USE SELECTED ITEM: SPACE ");
    info_message1.setCharacterSize(50); // in pixels, not points!
    info_message1.setFillColor(sf::Color::White);
    info_message1.setStyle(sf::Text::Bold);
    info_message1.setPosition(200, 300);

    info_message2.setFont(font);
    info_message2.setString(" SELECT INVENTORY: \n      SLOT 1: 1 \n      SLOT 2: 2\n      SLOT 3: 3\n      SLOT 4: 4 \n\n  PAUSE GAME: P");
    info_message2.setCharacterSize(50); // in pixels, not points!
    info_message2.setFillColor(sf::Color::White);
    info_message2.setStyle(sf::Text::Bold);
    info_message2.setPosition(700, 300);

    info_message3.setFont(font);
    info_message3.setString("                                           HELP FRED DEFEND THE WORLD AGAINST ALIEN INVADERS. \n            DURING THE DAY, PREPARE FOR THE ONCOMING INVASION BY PREPPING ITEMS, WEAPONS AND TRAPS. \n                                            DURING THE NIGHT, DEFEND THE FARM AGAINST THE ALIENS.");
    info_message3.setCharacterSize(40); // in pixels, not points!
    info_message3.setFillColor(sf::Color::White);
    info_message3.setStyle(sf::Text::Bold);
    info_message3.setPosition(50, 140);

    info_message4.setFont(font);
    info_message4.setString("                                   PRESS B TO RETURN TO THE MAIN MENU AND BEGIN YOUR ADVENTURE");
    info_message4.setCharacterSize(40); // in pixels, not points!
    info_message4.setFillColor(sf::Color::Yellow);
    info_message4.setStyle(sf::Text::Bold);
    info_message4.setPosition(50, 800);
    

    this->window->draw(tutorial);
    this->window->draw(tutorial_message);
    this->window->draw(info_message1);
    this->window->draw(info_message2);
    this->window->draw(info_message3);
    this->window->draw(info_message4);
    // this->window->display();
}
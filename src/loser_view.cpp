#include "loser_view.h"
#include "master_logic.h"
#include "master_view.h"
#include <iostream>


LoserView::LoserView(std::shared_ptr<MasterLogic>& logic, std::shared_ptr<sf::RenderWindow>& window)
    : View(logic) {
    this->window = window;

    loser_image.spriteMap.loadFromFile("../resources/losescreen.png");
    if (!font.loadFromFile("../resources/Amatic-Bold.ttf")) {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }

}

void LoserView::pollInput() {
    sf::Event Event;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = false;
        this->logic->loser = false;
    }

}

void LoserView::update(float delta) {

    this->pollInput();

    this->drawScreen();

}

void LoserView::drawScreen() {
    // this->window->clear(sf::Color::Black);

    loser.setSize(sf::Vector2f(1200, 900));
    loser.setTexture(&loser_image.spriteMap);


    //sf::Text options_message;
    tutorial_message.setFont(font);
    tutorial_message.setString("GAME OVER");
    tutorial_message.setCharacterSize(100); // in pixels, not points!
    tutorial_message.setFillColor(sf::Color::White);
    tutorial_message.setStyle(sf::Text::Bold);
    tutorial_message.setPosition(470, 650);

    info_message3.setFont(font);
    info_message3.setString("YOU LOSE! \n");
    info_message3.setCharacterSize(40); // in pixels, not points!
    info_message3.setFillColor(sf::Color::White);
    info_message3.setStyle(sf::Text::Bold);
    info_message3.setPosition(550, 770);

    info_message4.setFont(font);
    info_message4.setString("PRESS SPACE TO RETURN TO THE MAIN MENU AND TRY AGAIN");
    info_message4.setCharacterSize(40); // in pixels, not points!
    info_message4.setFillColor(sf::Color::Yellow);
    info_message4.setStyle(sf::Text::Bold);
    info_message4.setPosition(315, 825);


    this->window->draw(loser);
    this->window->draw(tutorial_message);
    this->window->draw(info_message3);
    this->window->draw(info_message4);
    // this->window->display();
}
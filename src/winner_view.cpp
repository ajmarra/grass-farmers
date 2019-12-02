#include "winner_view.h"
#include "master_logic.h"
#include "master_view.h"
#include <iostream>


WinnerView::WinnerView(std::shared_ptr<MasterLogic>& logic, std::shared_ptr<sf::RenderWindow>& window)
    : View(logic) {
    this->window = window;

    winner_image.spriteMap.loadFromFile("../resources/winscreen.png");
    if (!font.loadFromFile("../resources/Amatic-Bold.ttf")) {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }

}

void WinnerView::pollInput() {
    sf::Event Event;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = false;
        this->logic->winner = false;
    }

}

void WinnerView::update(float delta) {

    this->pollInput();

    this->drawScreen();

}

void WinnerView::drawScreen() {
    // this->window->clear(sf::Color::Black);

    winner.setSize(sf::Vector2f(1200, 900));
    winner.setTexture(&winner_image.spriteMap);


    //sf::Text options_message;
    winner_message.setFont(font);
    winner_message.setString("CONGRATULATIONS");
    winner_message.setCharacterSize(100); // in pixels, not points!
    winner_message.setFillColor(sf::Color::Black);
    winner_message.setStyle(sf::Text::Bold);
    winner_message.setPosition(400, 470);

    info_message1.setFont(font);
    info_message1.setString("YOU WIN! \n");
    info_message1.setCharacterSize(40); // in pixels, not points!
    info_message1.setFillColor(sf::Color::Black);
    info_message1.setStyle(sf::Text::Bold);
    info_message1.setPosition(550, 590);

    info_message2.setFont(font);
    info_message2.setString("PRESS SPACE TO RETURN TO THE MAIN MENU AND PLAY AGAIN");
    info_message2.setCharacterSize(40); // in pixels, not points!
    info_message2.setFillColor(sf::Color::Blue);
    info_message2.setStyle(sf::Text::Bold);
    info_message2.setPosition(315, 645);


    this->window->draw(winner);
    this->window->draw(winner_message);
    this->window->draw(info_message1);
    this->window->draw(info_message2);
    // this->window->display();
}
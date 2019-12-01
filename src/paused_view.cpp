#include "paused_view.h"
#include "master_logic.h"
#include "master_view.h"
#include "player_view.h"
#include "music.h"
#include <iostream>

PausedView::PausedView(std::shared_ptr<MasterLogic> &logic,  std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
        this->window = window;

        
        if (!font.loadFromFile("../resources/Amatic-Bold.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    }

void PausedView::pollInput() {
    sf::Event Event;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
        
        this->logic->paused = false;
        this->logic->playing = true;
        this->logic->options = false;
        //this->logic->startDemo();

}}

void PausedView::update(float delta){
    //std::cout << "ERROR 1" << std::endl;
    this -> pollInput();
    //std::cout << "ERROR 2" << std::endl;
    
    this-> drawScreen();
    //std::cout << "ERROR 3" << std::endl;
}

void PausedView::drawScreen(){

    this->window->clear(sf::Color::Black);
    
    sf::RectangleShape paused;
    
    paused.setSize(sf::Vector2f(1200, 900));
    paused.setFillColor(sf::Color(75,119,190));


    
    paused_message.setFont(font);
    paused_message.setString("PAUSED");
    paused_message.setCharacterSize(80); // in pixels, not points!
    paused_message.setFillColor(sf::Color::White);
    paused_message.setStyle(sf::Text::Bold);
    paused_message.setPosition(500, 300);

    paused_message_2.setFont(font);
    paused_message_2.setString("PRESS U TO CONTINUE");
    paused_message_2.setCharacterSize(80); // in pixels, not points!
    paused_message_2.setFillColor(sf::Color::White);
    paused_message_2.setStyle(sf::Text::Bold);
    paused_message_2.setPosition(370, 400);

    this->window->draw(paused);
    this->window->draw(paused_message);
    this->window->draw(paused_message_2);
    this->window->display();
}
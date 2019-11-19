#include "options_view.h"
#include "master_logic.h"
#include "master_view.h"
#include <iostream>

OptionsView::OptionsView(std::shared_ptr<MasterLogic> &logic,  std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
        this->window = window;

        options_image.spriteMap.loadFromFile("../resources/optionsscreen.png");
        if (!font.loadFromFile("../resources/Amatic-Bold.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    }

void OptionsView::configureKeys(sf::Event Event){

}

void OptionsView::pollInput() {
    sf::Event Event;

    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::)) {
    //     this->logic->paused = false;
    //     this->logic->playing = true;
    //     this->logic->options = false;
    //     //this->logic->startDemo();

    // }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = false;
    }
    else{
        configureKeys(Event);
    }


}

void OptionsView::update(float delta){

    this -> pollInput();

    this-> drawScreen();

}

void OptionsView::drawScreen(){
    this->window->clear(sf::Color::Black);

    sf::RectangleShape options;
    
    options.setSize(sf::Vector2f(1200, 900));
    options.setTexture(&options_image.spriteMap);
    

    sf::Text options_message;
    options_message.setFont(font);
    options_message.setString("OPTIONS MENU");
    options_message.setCharacterSize(100); // in pixels, not points!
    options_message.setFillColor(sf::Color::White);
    options_message.setStyle(sf::Text::Bold);
    options_message.setPosition(400, 50);
    this->window->draw(options);
    this->window->draw(options_message);
    this->window->display();
}
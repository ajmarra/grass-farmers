#include "menu_view.h"
#include "master_logic.h"
#include "master_view.h"
#include <iostream>

MenuView::MenuView(std::shared_ptr<MasterLogic> &logic,  std::shared_ptr<sf::RenderWindow> &window)
    : View(logic) {
        this->window = window;

        menu_image.spriteMap.loadFromFile("../resources/titlescreen.png");
        if (!font.loadFromFile("../resources/Amatic-Bold.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    }

void MenuView::pollInput() {
    sf::Event Event;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        this->logic->paused = false;
        this->logic->playing = true;
        this->logic->options = false;
        this->logic->startDemo();

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        this->logic->paused = true;
        this->logic->playing = false;
        this->logic->options = true;
        this->logic->startTutorial();
        //this->view->setOptions();

    }

}

void MenuView::update(float delta){
    //std::cout << "ERROR 1" << std::endl;
    this -> pollInput();
    //std::cout << "ERROR 2" << std::endl;
    
    this-> drawScreen();
    //std::cout << "ERROR 3" << std::endl;
}

void MenuView::drawScreen(){
    // this->window->clear(sf::Color::Black);

    sf::RectangleShape menu;
    
    menu.setSize(sf::Vector2f(1200, 900));
    menu.setTexture(&menu_image.spriteMap);
    

    sf::Text menu_message;
    menu_message.setFont(font);
    menu_message.setString("WELCOME TO FRED THE FARMER SAVES THE WORLD   \n                      PRESS T FOR TUTORIAL \n                  OR PRESS SPACE TO BEGIN");
    menu_message.setCharacterSize(80); // in pixels, not points!
    menu_message.setFillColor(sf::Color::White);
    menu_message.setStyle(sf::Text::Bold);
    menu_message.setPosition(180, 500);
    this->window->draw(menu);
    this->window->draw(menu_message);
    // this->window->display();
}
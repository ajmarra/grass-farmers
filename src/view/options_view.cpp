
#include "options_view.h"
#include <iostream>

OptionsView::OptionsView():options_view(sf::VideoMode(800,600,32), "options menu", sf::Style::Close){
    
}

//display start menu and options
void OptionsView::updateMenuView(){
    options_view.clear(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("../src/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }


    sf::Text options_message;
    options_message.setFont(font);
    options_message.setString("WELCOME TO FRED THE FARMER...\nOPTIONS MENU");
    options_message.setCharacterSize(40); // in pixels, not points!
    options_message.setFillColor(sf::Color::White);
    options_message.setStyle(sf::Text::Bold);
    options_message.setPosition(100, 50);
    options_view.draw(options_message);

    options_view.display();
}

void OptionsView::closeMenu(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)) // End menu loop and set player count
    {
        options_view.close();
        
    }
    
    
}
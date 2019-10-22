
#include "view/menu_view.h"
#include <SFML/Graphics.hpp>
#include "view/options_view.h"


//start menu for game

//initiate menuView - dummy initiator
MenuView::MenuView():menuView(sf::VideoMode(800,600,32), "main menu", sf::Style::Close){
    
}

//display start menu and options
void MenuView::updateMenuView(){
    menuView.clear(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("../src/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }


    sf::Text menu_message;
    menu_message.setFont(font);
    menu_message.setString("WELCOME TO FRED THE FARMER...\n");
    menu_message.setCharacterSize(40); // in pixels, not points!
    menu_message.setFillColor(sf::Color::White);
    menu_message.setStyle(sf::Text::Bold);
    menu_message.setPosition(100, 50);
    menuView.display();
}


        

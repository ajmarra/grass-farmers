//#include "view/options_view.h"
//#include "view/menu_view.h"
#include "view/screen_control.h"
#include <iostream>



void updateMenuView(sf::RenderWindow &window){
    window.clear(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("src/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }


    sf::Text menu_message;
    menu_message.setFont(font);
    menu_message.setString("WELCOME TO FRED THE FARMER\n  SAVES THE WORLD   \n PRESS O TO GO TO OPTIONS \nOR PRESS SPACE TO BEGIN");
    menu_message.setCharacterSize(40); // in pixels, not points!
    menu_message.setFillColor(sf::Color::White);
    menu_message.setStyle(sf::Text::Bold);
    menu_message.setPosition(100, 50);
    window.draw(menu_message);
    window.display();
}


//display start menu and options
void updateOptionsView(sf::RenderWindow &window){
    window.clear(sf::Color::Black);
    sf::Font font;
    if (!font.loadFromFile("src/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }


    sf::Text options_message;
    options_message.setFont(font);
    options_message.setString("WELCOME TO THE OPTIONS MENU\n PRESS M TO RETURN\n TO THE MAIN MENU");
    options_message.setCharacterSize(40); // in pixels, not points!
    options_message.setFillColor(sf::Color::White);
    options_message.setStyle(sf::Text::Bold);
    options_message.setPosition(100, 50);
    window.draw(options_message);

    window.display();
}

ScreenController::ScreenController(sf::RenderWindow &window){
    updateMenuView(window);
}
void ScreenController::switchScreens(sf::RenderWindow &window, sf::Event Event){
    if (sf::Event::KeyPressed == Event.type){        
        switch (Event.key.code){
            case sf::Keyboard::M:
                updateMenuView(window);
                break;
            case sf::Keyboard::O:
                updateOptionsView(window);
                break;

                //where game will be drawm
            case sf::Keyboard::Space:
                window.close();
                
            //     break;

    }}
}


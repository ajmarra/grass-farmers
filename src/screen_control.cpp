#include "screen_control.h"
#include "fred.h"
#include <iostream>


void updateMenuView(sf::RenderWindow &window, sf::Font &font){
    window.clear(sf::Color::Black);
   

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
void updateOptionsView(sf::RenderWindow &window, sf::Font &font){
    window.clear(sf::Color::Black);


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

ScreenController::ScreenController(sf::RenderWindow &window, sf::Font &font){
    updateMenuView(window, font);
}
void ScreenController::switchScreens(sf::RenderWindow &window, sf::Event Event, sf::Font &font, float delta){
    if (sf::Event::KeyPressed == Event.type){        
        switch (Event.key.code){
            case sf::Keyboard::M:
                updateMenuView(window, font);
                break;
            case sf::Keyboard::O:
                updateOptionsView(window, font);
                break;

                //where game will be drawm
            case sf::Keyboard::Space:
                window.close();
                
            //     break;

    }}
}


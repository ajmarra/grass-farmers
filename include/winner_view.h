#ifndef WINNER_VIEW_H
#define WINNER_VIEW_H

#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

class WinnerView : public View {

private:
    std::shared_ptr<sf::RenderWindow> window;

    void pollInput(void);

    //int level = 1;

    sf::Text winner_message;
    sf::Text info_message1;
    sf::Text info_message2;
    sf::RectangleShape winner;

    //void drawScreen(void);
    Graphics winner_image;
    sf::Font font;

public:

    WinnerView(std::shared_ptr<MasterLogic>& logic, std::shared_ptr<sf::RenderWindow>& window);
    void update(float delta);
    void drawScreen();



};

#endif
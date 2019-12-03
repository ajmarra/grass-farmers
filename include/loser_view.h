#ifndef LOSER_VIEW_H
#define LOSER_VIEW_H

#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

// View for when Fred runs out of health and the player loses
class LoserView : public View {

private:
    std::shared_ptr<sf::RenderWindow> window;

    void pollInput(void);

    //int level = 1;

    sf::Text loser_message;
    sf::Text info_message1;
    sf::Text info_message2;
    sf::RectangleShape loser;

    //void drawScreen(void);
    Graphics loser_image;
    sf::Font font;

public:

    LoserView(std::shared_ptr<MasterLogic>& logic, std::shared_ptr<sf::RenderWindow>& window);
    void update(float delta);
    void drawScreen();



};

#endif
#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <iostream>

#include "master_logic.h"
#include "master_view.h"

int main(int argc, char** argv) {
    // game window
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1200,900,32), "Fred the Farmer", sf::Style::Titlebar | sf::Style::Close);
    
    // game clock
    sf::Clock clock;

    // random
    srand((int) time(0));

    //delta time
    float delta;

    sf::Font font;
    if (!font.loadFromFile("../resources/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    std::shared_ptr<MasterLogic> logic = std::make_shared<MasterLogic>();
    std::shared_ptr<MasterView> view = std::make_shared<MasterView>(window);
    view->init(logic);
    logic->init(view);
    logic->startMenu();

    //game loop
    while (window->isOpen()) {
        delta = clock.getElapsedTime().asSeconds(); //can change to milliseconds if necessary
        clock.restart();

        window->clear(sf::Color::Black);

        logic->update(delta);
        view->update(delta);
     
        window->display();

        //check for window closed event
        sf::Event Event;
        while (window->pollEvent(Event))
            if (Event.type == sf::Event::Closed) window->close();
    }

    // Done.
    return 0;
}
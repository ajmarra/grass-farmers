#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <iostream>

#include "master_logic.h"
#include "master_view.h"

int main(int argc, char** argv) {
    //game window
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1200,900,64), "Fred the Farmer");
    
    //game clock
    sf::Clock clock;

    //delta time
    float delta;

    sf::Font font;
    if (!font.loadFromFile("../resources/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    
    MasterLogic logic;
    std::shared_ptr<MasterView> view = std::make_shared<MasterView>(window);
    view->init(logic.getActorList());
    logic.init(view);
    logic.startDemo();

    //game loop
    while (window->isOpen()) {
        delta = clock.getElapsedTime().asSeconds(); //can change to milliseconds if necessary
        clock.restart();

        logic.update(delta);
        view->update(delta);
        window->display();
    }

    // Done.
    return 0;
}
#include <SFML/Graphics.hpp>
#include <iostream>

#include "master_logic.h"
#include "master_view.h"
#include "screen_control.h"


int main(int argc, char** argv) {
    sf::RenderWindow App(sf::VideoMode(800,800,32), "Fred the Farmer");
    
    //for game clock
    sf::Clock clock;
    float delta;

    sf::Font font;
    if (!font.loadFromFile("../resources/bit5x3.ttf"))
    {
        // error...
        std::cout << "ERROR LOADING FONT FROM FILE" << std::endl;
    }
    MasterLogic logic;
    MasterView view(logic.getActorList(), App);

    // create main window
    ScreenController* ScreenControl = new ScreenController(App, font); //initiate start menu

    //displays the start menu until the user chooses an enemy difficulty or closes the menu
    //when the user chooses an enemy difficulty, it will automatically close the menu and open the pong game view
    while(App.isOpen()) {
        //game loop
        delta = clock.getElapsedTime().asSeconds(); //can change to milliseconds if necessary
        clock.restart();

        logic.update(delta);
        ScreenControl->update(App);
        sf::Event Event;
        while(App.pollEvent(Event)) {
            if(Event.type == sf::Event::Closed) {
                App.close();
                return 0;
            }
           ScreenControl->switchScreens(App, Event, font, delta);
        }
    }

    App.clear(sf::Color::Black);
    
    App.display();

    // Done.
    return 0;
}

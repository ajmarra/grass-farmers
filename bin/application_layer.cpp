#include <SFML/Graphics.hpp>

#include "master_logic.h"


int main(int argc, char** argv) {
    sf::RenderWindow App(sf::VideoMode(800,800,32), "Fred the Farmer");
    //MasterLogic logic;


    while(App.isOpen()) {
        //logic.update();

        sf::Event Event;
        while(App.pollEvent(Event)) {
            if(Event.type == sf::Event::Closed) {
                App.close();
                return 0;
            }
        }
    }
    return 0;
}

#include <SFML/Graphics.hpp>

#include "master_logic.h"
#include "master_view.h"


int main(int argc, char** argv) {
    sf::RenderWindow App(sf::VideoMode(800,800,32), "Fred the Farmer");
    MasterLogic logic;
    MasterView view(logic.getActorList(), App);


    while(App.isOpen()) {
        logic.update();

        sf::Event Event;
        while(App.pollEvent(Event)) {
            if(Event.type == sf::Event::Closed) {
                App.close();
                return 0;
            }
        }

        App.clear(sf::Color::Black);
        
        App.display();
    }
    return 0;
}

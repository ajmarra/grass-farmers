#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
    // create main window
    sf::RenderWindow App(sf::VideoMode(800,800,32), "Fred saves the world!");

    // start main loop
    while(App.isOpen())
    {
        // process events
        sf::Event Event;
        while(App.pollEvent(Event))
        {
            // Exit
            if(Event.type == sf::Event::Closed)
                App.close();
        }

        // clear screen and fill with black
        App.clear(sf::Color::Black);

        // display
        App.display();
    }

    // Done.
    return 0;
}

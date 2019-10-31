#ifndef screencontrol_h
#define screencontrol_h

#include <SFML/Graphics.hpp>

/**
 * displays the start menu until the user chooses an enemy difficulty or closes the menu
 * when the user chooses an enemy difficulty, it will automatically close the menu and open the pong game view
 */
class ScreenController {
    public:
    ScreenController(sf::RenderWindow &window, sf::Font &font);
    void switchScreens(sf::RenderWindow &window, sf::Event Event, sf::Font &font, float delta);
    void update(sf::RenderWindow &window);
    
};

void updateMenuView(sf::RenderWindow &window, sf::Font &font);
void updateOptionsView(sf::RenderWindow &window, sf::Font &font);

#endif
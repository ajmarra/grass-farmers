#ifndef screencontrol_h
#define screencontrol_h

#include <SFML/Graphics.hpp>
class ScreenController{
    public:
    ScreenController(sf::RenderWindow &window, sf::Font &font);
    void switchScreens(sf::RenderWindow &window, sf::Event Event, sf::Font &font);
    void update(sf::RenderWindow &window);
    
};

void updateMenuView(sf::RenderWindow &window, sf::Font &font);
void updateOptionsView(sf::RenderWindow &window, sf::Font &font);

#endif
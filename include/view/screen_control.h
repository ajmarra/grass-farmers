#ifndef screencontrol_h
#define screencontrol_h

#include <SFML/Graphics.hpp>
class ScreenController{
    public:
    ScreenController(sf::RenderWindow &window);
    void switchScreens(sf::RenderWindow &window, sf::Event Event);
    
};

void updateMenuView(sf::RenderWindow &window);
void updateOptionsView(sf::RenderWindow &window);

#endif
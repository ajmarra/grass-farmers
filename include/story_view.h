#ifndef story_view_h
#define story_view_h

#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class StoryView : public View {
    
private:
    std::shared_ptr<sf::RenderWindow> window;
    void pollInput();
    
    sf::Font font;
    sf::Text text;
    std::ifstream inFile;
    
    sf::RectangleShape fade;
    int fadeCoefficient;
    
    std::vector<std::string> inputList;
    
    std::list<std::shared_ptr<sf::Text>> textList;
    int curHeight = 180;
    
public:
    
    StoryView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);
    void update(float delta);
    void drawScreen();
    void updateText();
    
};

#endif

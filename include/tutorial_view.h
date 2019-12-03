
#ifndef tutorial_view_h
#define tutorial_view_h

#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

// Shows the tutorial for the game and all of the controls
class TutorialView : public View {

    private:
        std::shared_ptr<sf::RenderWindow> window;
        void pollInput(void);
        
        //int level = 1;

        sf::Text tutorial_message;
        sf::Text info_message1;
        sf::Text info_message2;
        sf::Text info_message3;
        sf::Text info_message4;
        sf::RectangleShape tutorial;



        //void drawScreen(void);
        Graphics tutorial_image;
        sf::Font font;

    public:
        
        TutorialView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);
        void update(float delta);
        void drawScreen();
        
        

};

#endif
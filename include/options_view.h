
#ifndef options_view_h
#define options_view_h

#include "music.h"
#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

class OptionsView : public View {

    private:
        std::shared_ptr<sf::RenderWindow> window;
        void pollInput(void);
        
        int level = 1;

        sf::Text RightPress_message;
        sf::Text UpPress_message;
        sf::Text LefttPress_message;
        sf::Text DownPress_message;

        sf::String RightPress_string;
        sf::String UpPress_string = "W";
        sf::String DownPress_string;
        sf::String LeftPress_string;
        sf::Text options_message;
        sf::RectangleShape options;


        
        

        //void drawScreen(void);
        Graphics options_image;
        sf::Font font;

    public:
        
        OptionsView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);
        void configureKeys(sf::Event &Event);
        void update(float delta);
        void drawScreen();

        sf::Keyboard::Key UpPress = sf::Keyboard::W;
        sf::Keyboard::Key RightPress = sf::Keyboard::D;
        sf::Keyboard::Key LeftPress = sf::Keyboard::A;
        sf::Keyboard::Key DownPress = sf::Keyboard::S;

        sf::Keyboard::Key Inv1 = sf::Keyboard::Num1;
        sf::Keyboard::Key Inv2 = sf::Keyboard::Num2;
        sf::Keyboard::Key Inv3 = sf::Keyboard::Num3;
        sf::Keyboard::Key Inv4 = sf::Keyboard::Num4;

        sf::Keyboard::Key PickUpPress = sf::Keyboard::J;
        sf::Keyboard::Key DropPress = sf::Keyboard::K;
        sf::Keyboard::Key AttackPress = sf::Keyboard::Space;
        sf::Keyboard::Key PausePress = sf::Keyboard::P;
        sf::Keyboard::Key OptionsPress = sf::Keyboard::O;

        sf::Keyboard::Key *selected = &UpPress;
        
        

};

#endif
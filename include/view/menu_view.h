
#ifndef menuview_h
#define menuview_h

#include <SFML/Graphics.hpp>
#include <iostream>

//header class for MenuView for Fred the Farmer
class MenuView{
    public:
        sf::RenderWindow menuView;
        MenuView();
        void goToOptionsMenu();
        void updateMenuView();
};

#endif
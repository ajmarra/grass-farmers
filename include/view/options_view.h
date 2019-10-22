#ifndef optionsview_h
#define optionsview_h

#include <SFML/Graphics.hpp>

class OptionsView{
    public:
        sf::RenderWindow options_view;
        OptionsView();
        void changeOptions();
        void closeMenu();
        void updateMenuView();
};

#endif
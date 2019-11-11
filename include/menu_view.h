
#ifndef menu_view_h
#define menu_view_h

#include "music.h"
#include "view.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

class MenuView : public View {

    private:
        std::shared_ptr<sf::RenderWindow> window;
        void pollInput(void);

        void drawScreen(void);

    public:
        
        MenuView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);

        void update(float delta);

};

#endif
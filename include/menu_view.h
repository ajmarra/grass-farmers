
#ifndef menu_view_h
#define menu_view_h

#include "music.h"
#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

/*Main menu of the game.  Either starts the game or shows the tutorial depending on input*/
class MenuView : public View {

    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterView> view;
        void pollInput(void);

        //void drawScreen(void);
        Graphics menu_image;
        sf::Font font;

    public:
        
        MenuView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);

        void update(float delta);
        void drawScreen();
        
        

};

#endif
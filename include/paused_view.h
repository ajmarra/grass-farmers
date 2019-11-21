
#ifndef paused_view_h
#define paused_view_h

#include "music.h"
#include "view.h"
#include "graphics.h"
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

class PausedView : public View {

    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<MasterView> view;
        void pollInput(void);

        sf::Text paused_message;

        sf::Font font;

    public:
        
        PausedView(std::shared_ptr<MasterLogic> &logic, std::shared_ptr<sf::RenderWindow> &window);

        void update(float delta);
        void drawScreen();
        
        

};

#endif
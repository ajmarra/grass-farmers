#ifndef FRED_VIEW_H
#define FRED_VIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>
#include <fstream>

#include "graphics.h"
#include "view.h"
#include "fred.h"
#include "room.h"
#include "exit.h"
#include "item.h"
#include "music.h"
#include "enemy.h"

/*Pretty much everything the player sees during the actual game.  All actor drawing done here.*/
class PlayerView : public View {
    private:
        std::shared_ptr<sf::RenderWindow> window;
        std::shared_ptr<Fred> fred;

        sf::RectangleShape sky;
        sf::RectangleShape darkness;
        bool night = true;

        Sounds cur_track;
        Graphics FredSprite;
        Graphics EnemySprite1;
        Graphics EnemySprite2;
        Graphics EnemySprite3;
        Graphics CherylSprite;
        Graphics farm_image;
        Graphics bed_image;
        Graphics exit_image;
        Graphics gun1_image;
        Graphics hoe_image;
        Graphics closet_image;
        Graphics barn_image;
        Graphics portalSprite;
        Graphics health_image;
        Graphics trap_image;
        Graphics unused_trap_image;
        Graphics shield_image;
        Graphics speed_image;

        sf::Font font;
        
		float elapsedTime = 0;

        void pollInput(void);

        void drawScreen(void);
    
        void drawClosetMenu();

        void drawActor(Actor &a);

        void drawEnemy(Enemy &e);

    public:
        PlayerView(std::shared_ptr<MasterLogic> logic, std::shared_ptr<Fred> fred, std::shared_ptr<sf::RenderWindow> window);

        void update(float delta);
    
        //void setCurrentRoom(std::shared_ptr<Room> currentRoom);
    
        //void setCurrentExit(std::shared_ptr<Exit> currentExit);
    
        void switchToDay();
    
        void switchToNight();
    
        void switchToStory();
};

#endif
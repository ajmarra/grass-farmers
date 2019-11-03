#ifndef CHARACTER_VIEW_H
#define CHARACTER_VIEW_H
#include "room.h"
#include "exit.h"
#include <SFML/Graphics.hpp>
//#include "master_logic.h"

class CharacterView {

private:
    int health, experience, level;
    std::shared_ptr<Room> curRoom;
    std::shared_ptr<Exit> curExit;
    std::shared_ptr<sf::RenderWindow> window;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:
    CharacterView(int health, int experience, int level, std::shared_ptr<sf::RenderWindow> window);

    void setExperience(int);
    void setLevel(int);
    
    int getExperience(void);
    int getLevel(void);
    
    void update(float delta);
    
    void setCurrentRoom(std::shared_ptr<Room> newCurRoom);
    void setCurrentExit(std::shared_ptr<Exit> newCurExit);
};

#endif

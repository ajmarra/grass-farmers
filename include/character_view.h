#ifndef CHARACTER_VIEW_H
#define CHARACTER_VIEW_H
#include "logic/room.h"
//#include "master_logic.h"

class CharacterView {

private:
    int health, experience, level;
    std::shared_ptr<Room> curRoom;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:
    CharacterView(int health, int experience, int level);

    void setExperience(int);
    void setLevel(int);
    
    int getExperience(void);
    int getLevel(void);
    
    void update(float delta);
    
    void setCurrentRoom(std::shared_ptr<Room> newCurRoom);
};

#endif

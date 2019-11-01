#ifndef CHARACTER_VIEW_H
#define CHARACTER_VIEW_H
#include "logic/room.h"
#include "master_logic.h"

class CharacterView {

private:
    int health, experience, level;
    MasterLogic& logic;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:
    CharacterView(int health, int experience, int level, MasterLogic& logic);

    void setExperience(int);
    void setLevel(int);
    
    int getExperience(void);
    int getLevel(void);
    
    void update();
};

#endif

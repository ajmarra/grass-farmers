#ifndef CHARACTER_VIEW_H
#define CHARACTER_VIEW_H
#include "logic/room.h"

class CharacterView {

private:
    int health, experience, level;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:
	CharacterView() {};
	
    CharacterView(int health, int experience, int level);

    void setExperience(int);
    
    int getExperience(void);
    int getLevel(void);
    
    void update();

    int getLevel(void);
};

#endif
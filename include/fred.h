#ifndef FRED_H
#define FRED_H

#include "character_view.h"

class Fred : public character_view {
    
private:
    int health, experience, level;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:

    Fred(int health, int experience, int level);

    void setExperience(int);
    void setLevel(int);

    int getExperience(void);
    int getLevel(void);
};

#endif //Fred_H

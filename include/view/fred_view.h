#ifndef FREDVIEW_H
#define FREDVIEW_H

#include "character_view.h"

class FredView : public character_view {
    
private:
    int health, experience, level;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:

    FredView(int health, int experience, int level);

    void setExperience(int);
    void setLevel(int);

    int getExperience(void);
    int getLevel(void);
};

#endif //FREDVIEW_H

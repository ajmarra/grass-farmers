#ifndef SHIELD_H
#define SHIELD_H

#include "item.h"
#include "character.h"

/*
* Shield items that can be used to make the player invincibile.  It's a consumable so only one use
* per shield item instance and the buff lasts for a certain amount of time.
*/
class Shield : public Item {
private:
    int buffTime = 3;

public:
    Shield(double x, double y, double width, double height, std::shared_ptr<Character> character);

    /*
    * Makes Fred invincible for a 3 seconds.
    */
    void use(int x, int y) override;

    int getBuffTime(void) { return buffTime; };
};

#endif //SHIELD_H
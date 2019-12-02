#ifndef HEALTH_ITEM_H
#define HEALTH_ITEM_H

#include "item.h"
#include "character.h"

/*
* Health items that can be used to heal the user.  It's a consumable so only one use
* per health item instance.
*/
class HealthItem : public Item {
    private:
        int healQuantity = 5;

    public:
        HealthItem(double x, double y, double width, double height);

        /*
        * Heals the character that uses the item
        */
        void use(int x, int y) override;

        int getHealQuantity(void) { return healQuantity; };
};

#endif //HEALTH_ITEM_H
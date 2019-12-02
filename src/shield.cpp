#include "item.h"
#include "shield.h"
#include "character.h"

Shield::Shield(double x, double y, double width, double height) :
    Item(ActorType::SHIELD, x, y, width, height, 1, true) {

}

void Shield::use(int x, int y) {
    if (this->getCharacter()->getBuffTime() <= 0) {
        this->getCharacter()->setBuffTime(buffTime);
        this->getCharacter()->setInvincibility(true);
        this->decreaseQuantity();
        if (this->getQuantity() < 1) {
            this->setUsedItem(true);
            this->getCharacter()->popItemAtIndex(this->getCharacter()->getSelectedIndex());
        }
    }
}
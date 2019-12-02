#include "item.h"
#include "shield.h"
#include "character.h"

Shield::Shield(double x, double y, double width, double height, std::shared_ptr<Character> fred) :
    Item(ActorType::SHIELD, x, y, width, height, 1, true, fred) {

}

void Shield::use(int x, int y) {
    if (this->getCharacter()->getBuffTime() <= 0) {
        this->getCharacter()->setBuffTime(3);
        this->getCharacter()->setInvincibility(true);
        this->decreaseQuantity();
        if (this->getQuantity() < 1) {
            this->setUsedItem(true);
            this->getCharacter()->popItemAtIndex(this->getCharacter()->getSelectedIndex());
        }
    }
}
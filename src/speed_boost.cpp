#include "item.h"
#include "speed_boost.h"
#include "character.h"

SpeedBoost::SpeedBoost(double x, double y, double width, double height) :
    Item(ActorType::SPEED_BOOST, x, y, width, height, 1, true) {

}

void SpeedBoost::use(int x, int y) {
    if (this->getCharacter()->getBuffTime() <= 0) {
        this->getCharacter()->setBuffTime(buffTime);
        this->getCharacter()->setMaxSpeed(275);
        this->decreaseQuantity();
        if (this->getQuantity() < 1) {
            this->setUsedItem(true);
            this->getCharacter()->popItemAtIndex(this->getCharacter()->getSelectedIndex());
        }
    }
}
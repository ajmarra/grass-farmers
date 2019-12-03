#include "fred.h"
#include "item.h"

Fred::Fred(double x, double y) : Character(ActorType::FRED, x, y, 64, 64, 10, 180, 200) {

}


void Fred::damage(int d) {
    Character::damage(d);
    fredDamageSound.playFredDamageSound();
    //play sound here
}
#include "item.h"
#include "trap.h"
#include "character.h"
#include <iostream>

Trap::Trap(double x, double y, double width, double height, std::shared_ptr<Character> fred) :
    Item(ActorType::TRAP, x, y, width, height, 1, true, fred) {
    this->x = x;
    this->y = y;
}

void Trap::use(int x, int y) {
    this->elapsedTime = 0;
    this->getCharacter()->sleep(3);
    this->getCharacter()->dropItem();
    this->isSet = true;
    this->setCanPickUp(false);
}

void Trap::update(float delta) {
    this->delta = delta;
}
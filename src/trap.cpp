#include "item.h"
#include "trap.h"
#include "character.h"
#include <iostream>

Trap::Trap(double x, double y, double width, double height) :
    Item(ActorType::TRAP, x, y, width, height, 1, true) {
    this->x = x;
    this->y = y;
}

void Trap::use(int x, int y) {
    this->elapsedTime = 0;
    /*while (this->elapsedTime <= 1000.0f) {
        this->getCharacter()->setCanMove(false);
        this->elapsedTime += this->delta;
    }*/
    if (this->elapsedTime > 1000.0f) this->getCharacter()->setCanMove(true);
    this->getCharacter()->dropItem();
    this->isSet = true;
    
}

void Trap::update(float delta) {
    this->delta = delta;
}
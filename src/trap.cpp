#include "item.h"
#include "trap.h"
#include "room.h"
#include "character.h"
#include <iostream>

Trap::Trap(double x, double y, double width, double height, std::shared_ptr<Character> fred) :
    Item(ActorType::TRAP, x, y, width, height, 1, true, fred) {
    this->x = x;
    this->y = y;
    this->setUsedItem(false);
    this->setCanPickUp(true);
}

void Trap::use(int x, int y) {
    this->elapsedTime = 0;
    this->getCharacter()->sleep(3);
    if (this->getQuantity() == 1) {
        this->getCharacter()->dropItem();
        this->setCanPickUp(false);
    }
    else {
        this->decreaseQuantity();
        std::shared_ptr<Trap> item = std::make_shared<Trap>(this->getCharacter()->getCenterX(), this->getCharacter()->getCenterY(), 64, 64, this->getCharacter());
        item->setCanPickUp(false);
        this->getCharacter()->getCurrentRoom()->addActor(item);
    }
}

void Trap::update(float delta) {
    this->delta = delta;
}
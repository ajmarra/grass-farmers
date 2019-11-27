#include "bed.h"

Bed::Bed(ActorType type, double x, double y, double width, double height, int healAmt) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->type = type;
    this->healAmount = healAmt;
}

int Bed::getHealAmount() {
    return this->healAmount;
}

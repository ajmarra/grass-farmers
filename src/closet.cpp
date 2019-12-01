#include "closet.h"

Closet::Closet(ActorType type, double x, double y, double width, double height) : Actor(type, x, y, width, height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

std::shared_ptr<Item> Closet::getItemAtIndex(int index) {
    if (index >= 20) return NULL;
    return this->closetItems[index];
}

void Closet::putItemAtIndex(int index, std::shared_ptr<Item> newItem) {
    if (index < 20) {
        closetItems[index] = newItem;
    }
}

#include "room.h"
#include "actor.h"
#include "fred.h"
#include "exit.h"
#include "enemy.h"
#include "item.h"
#include "bullet.h"

Room::Room(double x, double y, double width, double height) : Actor(ActorType::ROOM, x, y, width, height) { }

void Room::addActor(std::shared_ptr<Fred> fred) {
    this->actorList.emplace_back(fred);
    this->fred = fred;
}

void Room::addActor(std::shared_ptr<Exit> exit) {
    this->actorList.emplace_back(exit);
    this->exitList.emplace_back(exit);
}

void Room::addActor(std::shared_ptr<Enemy> enemy) {
    this->actorList.emplace_back(enemy);
    this->enemyList.emplace_back(enemy);
}

void Room::addActor(std::shared_ptr<Item> item) {
    this->actorList.emplace_back(item);
    this->itemList.emplace_back(item);
}

void Room::addActor(std::shared_ptr<Bullet> bullet) {
    this->actorList.emplace_back(bullet);
    this->bulletList.emplace_back(bullet);
}
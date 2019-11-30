#include "actor.h"
#include "room.h"
#include "fred.h"
#include "exit.h"
#include "enemy.h"
#include "item.h"
#include "bullet.h"
#include "range_weapon.h"

Room::Room(double x, double y, double width, double height) : Actor(ActorType::ROOM, x, y, width, height) { }

void Room::addActor(std::shared_ptr<Exit> exit) {
    this->actorList.emplace_back(exit);
    this->exitList.emplace_back(exit);
}

void Room::addActor(std::shared_ptr<Fred> fred) {
    this->actorList.emplace_back(fred);
    this->fred = fred;

    this->fred->setCurrentRoom(this->shared_from_this());
}

void Room::addActor(std::shared_ptr<Enemy> enemy) {
    this->actorList.emplace_back(enemy);
    this->enemyList.emplace_back(enemy);
    enemy->setCurrentRoom(this->shared_from_this());
}
void Room::addActor(std::shared_ptr<Item> item) {

    this->actorList.emplace_back(item);
    this->itemList.emplace_back(item);
}
/**
void Room::addActor(std::shared_ptr<HealthItem> health) {
    this->actorList.emplace_back(health);
    this->itemList.emplace_back(health);
    this->healthItemList.emplace_back(health);
}

void Room::addActor(std::shared_ptr<RangeWeapon> weapon) {
    this->actorList.emplace_back(weapon);
    this->itemList.emplace_back(weapon);
    this->rangeWeaponList.emplace_back(weapon);
}

void Room::addActor(std::shared_ptr<Trap> trap) {
    this->actorList.emplace_back(trap);
    this->itemList.emplace_back(trap);
    this->trapList.emplace_back(trap);
}
*/
void Room::addActor(std::shared_ptr<Bullet> bullet) {
    this->actorList.emplace_back(bullet);
    this->bulletList.emplace_back(bullet);
}

void Room::addActor(std::shared_ptr<Portal> portal) {
    this->actorList.emplace_back(portal);
    this->portalList.emplace_back(portal);
}
void Room::removeActor(std::shared_ptr<Exit> exit) {
    this->actorList.remove(exit);
    this->exitList.remove(exit);
}

void Room::removeActor(std::shared_ptr<Fred> fred) {
    this->actorList.remove(fred);
    this->fred = fred;
}

void Room::removeActor(std::shared_ptr<Enemy> enemy) {
    if (enemy->getSelectedItem() != nullptr) {
        this->addActor(enemy->getSelectedItem());
        enemy->dropItem();
    }
    this->actorList.remove(enemy);
    this->enemyList.remove(enemy);
}

void Room::removeActor(std::shared_ptr<Item> item) {
    this->actorList.remove(item);
    this->itemList.remove(item);
}
/**
void Room::removeActor(std::shared_ptr<HealthItem> healthItem) {
    this->actorList.remove(healthItem);
    this->itemList.remove(healthItem);
    this->healthItemList.remove(healthItem);
}

void Room::removeActor(std::shared_ptr<RangeWeapon> rangeWeapon) {
    this->actorList.remove(rangeWeapon);
    this->itemList.remove(rangeWeapon);
    this->rangeWeaponList.remove(rangeWeapon);
}

void Room::removeActor(std::shared_ptrenemy<Trap> trap) {
    this->actorList.remove(trap);
    this->itemList.remove(trap);
    this->trapList.remove(trap);
}
*/
void Room::removeActor(std::shared_ptr<Bullet> bullet) {
    this->actorList.remove(bullet);
    this->bulletList.remove(bullet);
}

void Room::removeActor(std::shared_ptr<Portal> portal) {
    this->actorList.remove(portal);
    this->portalList.remove(portal);
}
#ifndef ROOM_H
#define ROOM_H

#include <list>
#include <memory>

#include "actor.h"
#include "character.h"
//#include "fred.h"
#include "item.h"
//#include "enemy.h"
#include "bullet.h"

class Exit;
class Fred;
class Enemy;

class Room : public Actor {
    private:
        // Actor lists

        std::list<std::shared_ptr<Actor>> actorList;
        std::shared_ptr<Fred> fred;
        std::list<std::shared_ptr<Exit>> exitList;
        std::list<std::shared_ptr<Enemy>> enemyList;
        std::list<std::shared_ptr<Item>> itemList;
        std::list<std::shared_ptr<Bullet>> bulletList;
        
    public:
        Room(double x, double y, double width, double height);
        
        void setActorList(std::list<std::shared_ptr<Actor>> newActorList) { this->actorList = newActorList; };

        /**
         * Adds an actor to the actor list in the proper section for actors of its type.
         */
        void addActor(std::shared_ptr<Fred> fred);

        void addActor(std::shared_ptr<Exit> exit);

        void addActor(std::shared_ptr<Enemy> enemy);

        void addActor(std::shared_ptr<Item> item);

        void addActor(std::shared_ptr<Bullet> bullet);

        std::shared_ptr<Fred> getFred(void) { return this->fred; };
        
        std::list<std::shared_ptr<Exit>> getExitList(void) { return this->exitList; };
        
        std::list<std::shared_ptr<Enemy>> getEnemyList(void) { return this->enemyList; };
        
        std::list<std::shared_ptr<Item>> getItemList(void) { return this->itemList; };
        
        std::list<std::shared_ptr<Bullet>> getBulletList(void) { return this->bulletList; };

        /**
         * Return the whole list of actors.
         */
        std::list<std::shared_ptr<Actor>> getActorList(void) { return this->actorList; };

        std::shared_ptr<Fred> getFred(ActorType t) { return this->fred; };
};

#endif
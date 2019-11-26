#include "exit.h"
#include "actor.h"
#include "room.h"

Exit::Exit(double x, double y, std::list<std::shared_ptr<Room>>::iterator destination) : Actor(ActorType::EXIT, x, y, 64, 10) {
    this->destination = destination;
}
#include "exit.h"
#include "actor.h"
#include "room.h"

Exit::Exit(double x, double y, std::shared_ptr<Room> destination) : Actor(ActorType::EXIT, x, y, 64, 10) {
    this->destination = destination;
}
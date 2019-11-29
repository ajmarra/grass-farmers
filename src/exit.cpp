#include "exit.h"
#include "actor.h"
#include "room.h"

Exit::Exit(double x, double y, int destination) : Actor(ActorType::EXIT, x, y, 12, 64) {
    this->destination = destination;
}
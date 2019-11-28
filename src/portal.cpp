#include "actor.h"
#include "portal.h"

Portal::Portal(double x, double y) :
    Actor(ActorType::PORTAL, x, y, 128, 128) {
}

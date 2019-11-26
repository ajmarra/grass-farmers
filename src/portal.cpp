#include "actor.h"
#include "portal.h"

Portal::Portal(double x, double y, double width, double height) :
    Actor(ActorType::PORTAL, x, y, width, height) {
}

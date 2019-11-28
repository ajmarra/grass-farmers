#ifndef PORTAL_H
#define PORTAL_H

#include "actor.h"

/*
* Portal actors where enemies spawn in during the night.
* Portals disappear during the day.
*/
class Portal : public Actor {

public:
    Portal(double x, double y);


};

#endif //PORTAL_H
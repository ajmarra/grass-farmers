//
//  exit.h
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#ifndef exit_h
#define exit_h

#include "logic/actor.h"
#include "logic/room.h"

class Exit :: public Actor {
protected:
    Room& destination;
    
public:
    void setDestination(Room& newDest);
    Room& getDestination();
}

#endif /* exit_h */

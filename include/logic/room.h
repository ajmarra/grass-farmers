//
//  room.hpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include "logic/actor.h"
#include "logic/exit.h"

class Room : public Actor {
protected:
    &Exit exit;
    
public:
    Room(double x, double y, double width, double height, &Exit exit);
    &Exit getExit();
}

#endif /* room_hpp */

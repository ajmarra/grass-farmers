//
//  room.hpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include <logic/actor.h>

class Room : public Actor {
public:
    Room(double x, double y, double width, double height);
};

#endif /* room_hpp */

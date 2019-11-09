//
//  room.hpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#ifndef room_hpp
#define room_hpp

#include <stdio.h>
#include <actor.h>
#include <item.h>
#include <list>
#include <memory>

class Room : public Actor {
private:
    std::list<std::shared_ptr<Actor>> actorList;
    
public:
    Room(double x, double y, double width, double height);
    
    void setActorList(std::list<std::shared_ptr<Actor>> newActorList);
    
    std::list<std::shared_ptr<Actor>> getActorList();
};

#endif /* room_hpp */

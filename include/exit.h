//
//  exit.h
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#ifndef exit_h
#define exit_h

#include <memory>
#include <actor.h>
#include <room.h>

class Exit : public Actor {
protected:
    std::shared_ptr<Room> destination;
    
public:
    Exit(double x, double y, double width, double height, std::shared_ptr<Room> destination);
    std::shared_ptr<Room> getDestination();
    void setDestination(std::shared_ptr<Room> newDest);
};

#endif /* exit_h */

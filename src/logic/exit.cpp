//
//  exit.cpp
//  
//
//  Created by Sean Thomson on 10/19/19.
//

#include <stdio.h>

void Exit::setDestination(Room& newDest) {
    this->destination = newDest;
}

&Room Exit::getDestination() {
    return destination;
}

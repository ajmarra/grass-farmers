#include "graphics.h"
#include <iostream>

Graphics::Graphics(){}

// void Graphics::addFrame(Frame&& frame){
//     total
// }

void Graphics::update(float delta){
    elapsedTime += delta;

    //std::cout << delta << std::endl;
    //std::cout << direction << std::endl;
    
    
    if ((elapsedTime >= frameRate)){


        elapsedTime -= frameRate;

        spriteFrame.left += 64;
        //in case it goes off array map
        if (spriteFrame.left >= 128) {
            spriteFrame.left = 0;
        }
        
    }}
      
void Graphics::setSprite(double direction){
    //up 1
    if ((direction >= -135.0) && (direction < -45.0)){
        spriteFrame.top = 196;


    }

    // //left1
    else if ((((direction < -135.0) && (direction >= -180.0)) || 
    ((direction <= 180.0) && (direction > 135.0)))){
        spriteFrame.top = 128;


    }

    //down 1
    else if ((direction <= 135.0) && (direction > 45.0)){
        spriteFrame.top = 64;


    }


    // //right1
    else if ((((direction < 45.0) && (direction > 0.0)) || 
    ((direction >= -45.0) && (direction <0.0))))
        {
        spriteFrame.top = 0;


    }    
}

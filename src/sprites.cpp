#include "sprites.h"
#include <iostream>

Sprite::Sprite(){}

void Sprite::update(float delta, double direction){
    elapsedTime += delta;
    std::cout << direction << std::endl;
    
    
    if (elapsedTime >= frameRate){


        elapsedTime -= frameRate;

        //in case it goes off array map
        if (cur_sprite.x >= cur_sprite.x) {
            cur_sprite.x = 0;
        } }
        
       
       //up 1
        if ((direction >= -135.0) && (direction < -45.0) && (move = 0)){
            spriteFrame.left = 196;
            spriteFrame.left = 0;
            move = 1;

        }

        //up2
        else if ((direction >= -135.0) && (direction < -45.0) && (move = 1)){
            spriteFrame.left = 196;
            spriteFrame.left = 64;
            move = 0;

        }

//left1
        else if ((((direction < -135.0) && (direction >= -180.0)) || 
        ((direction <= 180.0) && (direction > 135.0)))
         && (move = 0)){
            spriteFrame.top = 128;
            spriteFrame.left = 0;
            move = 1;

        }

        //left2
        else if ((((direction < -135.0) && (direction >= -180.0)) || 
        ((direction <= 180.0) && (direction > 135.0)))
         && (move = 1)){
            spriteFrame.top = 128;
            spriteFrame.left = 0;
            move = 0;

        }

        //down 1
        else if ((direction <= 135.0) && (direction > 45.0) && (move = 0)){
            spriteFrame.left = 64;
            spriteFrame.left = 0;
            move = 1;

        }

        //down 2
         else if ((direction <= 135.0) && (direction > 45.0) && (move = 1)){
            spriteFrame.left = 64;
            spriteFrame.left = 0;
            move = 0;

        }

        //right1
        else if ((((direction < 45.0) && (direction > 0.0)) || 
        ((direction <= -45.0) && (direction <0.0)))
         && (move = 0)){
            spriteFrame.top = 0;
            spriteFrame.left = 0;
            move = 1;

        }

        //right2
        else if ((((direction < 45.0) && (direction > 0.0)) || 
        ((direction <= -45.0) && (direction <0.0)))
         && (move = 1)){
            spriteFrame.top = 0;
            spriteFrame.left = 0;
            move = 0;

        }




        // else if ((((direction >= 315.0) && (direction < 360.0)) || 
        //     ((direction >= 0.0) && (direction < 45.0))) &&
        //  (move = 0)){
        //     spriteFrame.top = 0;
        //     spriteFrame.left = 0;
        //     move = 1;

        // }
        // else if ((((direction >= 315.0) && (direction < 360.0)) || 
        //     ((direction >= 0.0) && (direction < 45.0))) &&
        //  (move = 1)){
        //     spriteFrame.top = 0;
        //     spriteFrame.left = 0;
        //     move = 0;

        // }


    
}

//spriteFrame.left = 128;
//paddle.setTextureRect(spriteFrame);
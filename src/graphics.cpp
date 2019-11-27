#include "graphics.h"
#include <iostream>

void Graphics::updateFred(float delta) {
    elapsedFredTime += delta;

    //std::cout << delta << std::endl;
    //std::cout << direction << std::endl;
    
    if (elapsedFredTime >= frameRate) {
        elapsedFredTime -= frameRate;

        spriteFrame.left += 64;

        if (spriteFrame.left >= 128) spriteFrame.left = 0; //in case it goes off array map
    }
}

void Graphics::updateEnemy(float delta) {
    elapsedEnemyTime += delta;

    if (elapsedEnemyTime >= frameRate && left == 0) {
        elapsedEnemyTime -= frameRate;

        spriteFrame.left += 64;
        //in case it goes off array map
        if (spriteFrame.left >= 128) spriteFrame.left = 0;
    }

    else if (elapsedEnemyTime >= frameRate && left == 1) {
        elapsedEnemyTime -= frameRate;

        spriteFrame.top += 64;
        //in case it goes off array map
        if (spriteFrame.top >= 128) spriteFrame.top = 0;        
    }
}
      
void Graphics::setFredSprite(double direction) {
    //up 1
    if (direction >= -135.0 && direction < -45.0) spriteFrame.top = 196;

    //left1
    else if (direction < -135.0 && direction >= -180.0 || direction <= 180.0 && direction > 135.0) spriteFrame.top = 128;

    //down 1
    else if (direction <= 135.0 && direction > 45.0) spriteFrame.top = 64;

    //right1
    else if (direction < 45.0 && direction > 0.0 || direction >= -45.0 && direction < 0.0) spriteFrame.top = 0;
}

void Graphics::setEnemySprite(double direction) {
    //up 1
    if (direction >= -135.0 && direction < -45.0) {
        spriteFrame.top = 0;
        left = 0;
    }

    //left1
    else if (direction < -135.0 && direction >= -180.0 || 
    direction <= 180.0 && direction > 135.0) {
        spriteFrame.top = 0;
        spriteFrame.left = 128;
        left = 1;
    }

    //down 1
    else if (direction <= 135.0 && direction > 45.0) {
        spriteFrame.top = 64;
        left = 0;
    }

    //right1
    else if (direction < 45.0 && direction > 0.0 || direction >= -45.0 && direction <0.0) {
        spriteFrame.top = 128;
        left = 0;
    }
}
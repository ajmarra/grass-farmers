#include "graphics.h"
#include <iostream>

void Graphics::updateFred(float delta) {
    elapsedFredTime += delta;

    
    
    if ((elapsedFredTime >= frameRateFred)){

        
        //elapsedFredTime -= frameRate;

        spriteFrame.left += 64;
        //in case it goes off array map
        if (spriteFrame.left >= 128) {
            spriteFrame.left = 0;
        }
    elapsedFredTime  = 0;
        
    }
    
    }


void Graphics::updateEnemy(float delta) {
    elapsedEnemyTime += delta;

    //std::cout << delta << std::endl;
    //std::cout << direction << std::endl;

    
    
    
    if ((elapsedEnemyTime >= frameRateEnemy)){
        
        //for left
        if (leftEnemy == true){
            spriteFrame.top += 64;
            //in case it goes off array map
            if (spriteFrame.top >= 128) {
                spriteFrame.top = 0;
        }
        }

        //for all other directions
        else if (leftEnemy == false){        
            
        

            spriteFrame.left += 64;
            //in case it goes off array map
            if (spriteFrame.left >= 128) {
                spriteFrame.left = 0;
            }}

        elapsedEnemyTime = 0;
        
        
    }}

void Graphics::updatePortal(float delta) {
    elapsedPortalTime += delta;

    
    
    if ((elapsedPortalTime >= frameRatePortal)){


        spriteFrame.left += 128;
        //in case it goes off array map
        if (spriteFrame.left >= 256) {
            spriteFrame.left = 0;
        } 
    elapsedPortalTime  = 0;
        
    }
    
    }

void Graphics::updateCheryl(float delta) {
    elapsedCherylTime += delta;
    
    
    
    if ((elapsedCherylTime >= frameRateCheryl)){
        
        //for left
        if (leftCheryl == true){
            spriteFrame.top += 100;
            //in case it goes off array map
            if (spriteFrame.top >= 200) {
                spriteFrame.top = 0;
        }
        }

        //for all other directions
        else if (leftCheryl == false){        
            
        

            spriteFrame.left += 100;
            //in case it goes off array map
            if (spriteFrame.left >= 200) {
                spriteFrame.left = 0;
            }}

        elapsedCherylTime = 0;
        
        
    }}


    
      
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

        
        if(spriteFrame.left >= 128){
            spriteFrame.left = 0;
        }
        spriteFrame.top = 0;
        leftEnemy = false;



    }

    // //left1
    else if ((((direction < -135.0) && (direction >= -180.0)) || 
    ((direction <= 180.0) && (direction > 135.0)))){

        if(spriteFrame.top >= 128){
        spriteFrame.top = 0;
        }
        //spriteFrame.top = 0;
        spriteFrame.left = 128;
        leftEnemy = true;


    }

    //down 1
    else if (direction <= 135.0 && direction > 45.0) {
        if(spriteFrame.left >= 128){
            spriteFrame.left = 0;
        }

        spriteFrame.top = 64;
        leftEnemy = false;


    }

    //right1
    else if (direction < 45.0 && direction > 0.0 || direction >= -45.0 && direction <0.0) {
        if(spriteFrame.left >= 128){
            spriteFrame.left = 0;
        }
        spriteFrame.top = 128;
        leftEnemy = false;


    }
}

      
void Graphics::setCherylSprite(double direction) {
    //up 1
    if (direction >= -135.0 && direction < -45.0) {

        
        if(spriteFrame.left >= 200){
            spriteFrame.left = 0;
        }
        spriteFrame.top = 200;
        leftCheryl = false;



    }

    // //right1
    else if (direction < 45.0 && direction > 0.0 || direction >= -45.0 && direction <0.0) {
   // else if ((((direction < -135.0) && (direction >= -180.0)) || 
    //((direction <= 180.0) && (direction > 135.0)))){

        if(spriteFrame.top >= 200){
        spriteFrame.top = 0;
        }
        //spriteFrame.top = 0;
        spriteFrame.left = 200;
        leftCheryl = true;


    }

    //down 1
    else if (direction <= 135.0 && direction > 45.0) {
        if(spriteFrame.left >= 200){
            spriteFrame.left = 0;
        }

        spriteFrame.top = 0;
        leftCheryl = false;


    }

    //left1
    else if ((((direction < -135.0) && (direction >= -180.0)) || 
    ((direction <= 180.0) && (direction > 135.0)))){
        if(spriteFrame.left >= 200){
            spriteFrame.left = 0;
        }
        spriteFrame.top = 100;
        leftCheryl = false;


    }
}

      
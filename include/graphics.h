#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SFML/Graphics.hpp>
#include <iostream>

/** 
 * header class for Paddles for Pong
 */
class Graphics {
    private:
        bool leftEnemy = false;
        bool leftCheryl = false;
        sf::Vector2u totalSprite;
        sf::Vector2f cur_sprite;
        float frameRateFred = 0.3;
        float frameRateEnemy = 0.3;
        float frameRatePortal = 0.5;
        float frameRateCheryl = 0.4;
        float elapsedFredTime;
        float elapsedEnemyTime;
        float elapsedPortalTime;
        float elapsedCherylTime;
        float currentFrame;
        //int move = 0; 

    public:
        Graphics() { };
        
        sf::Texture spriteMap;
        
        sf::IntRect spriteFrame;
        
        void updateFred(float delta);
        
        void setFredSprite(double direction);
        
        void updateEnemy (float delta);

        void updatePortal(float delta);
        
        void setEnemySprite(double direction);

        void updateCheryl(float delta);
        
        void setCherylSprite(double direction);


};

#endif
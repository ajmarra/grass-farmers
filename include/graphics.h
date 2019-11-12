//Rachel Oberman
//CSCI 437
#ifndef graphics_h
#define graphics_h
#include <SFML/Graphics.hpp>
#include <iostream>



//header class for Paddles for Pong
class Graphics{
    public:
        Graphics();
        sf::Texture spriteMap;
        sf::IntRect spriteFrame;
        void updateFred(float delta);
        void setFredSprite(double direction);
        void updateEnemy (float delta);
        void setEnemySprite(double direction);


    

    private:
        int left = 0;
        sf::Vector2u totalSprite;
        sf::Vector2f cur_sprite;
        float frameRate = 0.3;
        float elapsedFredTime;
        float elapsedEnemyTime;
        float currentFrame;
        //int move = 0; 
};

#endif
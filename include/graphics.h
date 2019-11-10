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
        void update (float delta);
        void setSprite(double direction);

    

    private:
        sf::Vector2u totalSprite;
        sf::Vector2f cur_sprite;
        float frameRate = 0.3;
        float elapsedTime;
        float currentFrame;
        int move = 0; 
};

#endif
//Rachel Oberman
//CSCI 437
#ifndef sprites_h
#define sprites_h
#include <SFML/Graphics.hpp>
#include <iostream>


//header class for Paddles for Pong
class Sprite{
    public:
        Sprite();
        sf::Texture spriteMap;
        sf::IntRect spriteFrame;
        void update (float delta, double direction);

    

    private:
    sf::Vector2u cur_sprite;
    float frameRate = 32;
    float elapsedTime;
    float currentFrame;
    int move = 0; 
};

#endif
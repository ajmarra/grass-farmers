
#ifndef music_h
#define music_h
#include <SFML/Audio.hpp>
#include <iostream>

//  Manages all of the music and sound effects for the game.
class Sounds{
    public:
        Sounds();
        void playDayTrack();
        void playNightTrack();
        void stopCurrentTrack();
        void pauseCurrentTrack(); //to be implemented later
        void playCurrentTrack();
        void playPewSound();
        void playSwooshSound();
        void playFredDamageSound();
        void playCherylDamageSound();



    private:
        sf::Music day_track;
        sf::Music night_track;
        sf::Music *current_track; //keep track of what is being played to stop/pause as necessary
        sf::SoundBuffer pewBuffer;
        sf::Sound pewSound;
        sf::SoundBuffer swooshBuffer;
        sf::Sound swooshSound;
        sf::SoundBuffer fredDamageBuffer;
        sf::Sound fredDamageSound;
        sf::SoundBuffer cherylDamageBuffer;
        sf::Sound cherylDamageSound;
};

#endif
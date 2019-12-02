
#ifndef music_h
#define music_h
#include <SFML/Audio.hpp>
#include <iostream>

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
};

#endif
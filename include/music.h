
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

    private:
        sf::Music day_track;
        sf::Music night_track;
        sf::Music *current_track; //keep track of what is being played to stop/pause as necessary
};

#endif
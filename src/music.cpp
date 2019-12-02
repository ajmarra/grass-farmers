#include "music.h"

Sounds::Sounds(){
    pewBuffer.loadFromFile("../resources/pewpew.ogg");
    pewSound.setBuffer(pewBuffer);

    swooshBuffer.loadFromFile("../resources/swoosh.ogg");
    swooshSound.setBuffer(swooshBuffer);
    fredDamageBuffer.loadFromFile("../resources/fred_damage.ogg");
    fredDamageSound.setBuffer(fredDamageBuffer);
}

void Sounds::playDayTrack(){
    if (!day_track.openFromFile("../resources/Eric_Lash_Day_Time_Score.ogg"))
    {
        // error...
        std::cout << "ERROR LOADING DAY TRACK FROM FILE" << std::endl;
    }
    current_track = &day_track;
    day_track.play();
    day_track.setLoop(true);
    
}

void Sounds::playNightTrack(){
    if (!night_track.openFromFile("../resources/Eric_Lash_Night_Time_Battle_Score.ogg"))
    {
        // error...
        std::cout << "ERROR LOADING NIGHT TRACK FROM FILE" << std::endl;
    }
    current_track = &night_track;
    night_track.play();
    night_track.setLoop(true);
    
}

void Sounds::stopCurrentTrack(){
    current_track->stop();
    
}

void Sounds::pauseCurrentTrack(){
    current_track->pause();
    
}

void Sounds::playCurrentTrack(){
    current_track->play();
}

void Sounds::playPewSound(){
    pewSound.setVolume(50);
    pewSound.play();
    
}

void Sounds::playSwooshSound(){
    swooshSound.play();
}

void Sounds::playFredDamageSound(){
    fredDamageSound.play();
}
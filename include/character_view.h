#ifndef CHARACTER_VIEW_H
#define CHARACTER_VIEW_H

class CharacterView {

private:
    int health, experience, level;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object

public:
	CharacterView() {};
	
    CharacterView(int health, int experience, int level);

    void setExperience(int);
    
    int getExperience(void);

    void setLevel(int);

    int getLevel(void);
};

<<<<<<< Updated upstream:include/character_view.h
#endif
=======
#endif
>>>>>>> Stashed changes:include/view/character_view.h

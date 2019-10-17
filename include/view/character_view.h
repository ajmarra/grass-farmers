#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

class CharacterView {

private:
    int health, experience, level;
    int inventory[5]; //Temporary -- Needs to be replaced with Item object



public:

	CharacterView() {};
	CharacterView(int health, int experience, int level);

    void setExperience(int);
    void setLevel(int);

    int getExperience(void);
    int getLevel(void);


};
#endif // CHARACTERVIEW_H

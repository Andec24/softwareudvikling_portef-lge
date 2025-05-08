#ifndef HERO_H
#define HERO_H

#include "Character.h"

class Hero : public Character {
private:
    int xp;
    int level;
    

public:
    Hero(const string& name);
    void gainXp(int amount);
    void levelUp();
    void displayStats() const override;
 
};

#endif // HERO_H
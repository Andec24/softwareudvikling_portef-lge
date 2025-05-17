#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Weapon.h"

class Hero : public Character {
private:
    int xp;
    int level;
    int gold;
    Weapon* weapon = nullptr;

public:
    Hero(const string& name);
    void gainXp(int amount);
    void levelUp();
    void displayStats() const override;
    void obtainGold(int amount);
    int getLevel();
    void equipWeapon(Weapon* weapon);
    Weapon* getWeapon() const override;
    
 
};

#endif // HERO_H
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "Weapon.h"
using namespace std;

class Character {
protected:
    string name;
    int currentHp;
    int maxHp;
    int strength;

public:
    Character(const string& name, int hp, int strength);
    virtual ~Character();

    const string& getName() const;
    int getHp() const;
    int getStrength() const;

    virtual void takeDamage(int damage);
    virtual void resetHp();
    virtual void attack(Character& target);
    virtual void displayStats() const;
    virtual Weapon* getWeapon() const; 

};

#endif // CHARACTER_H
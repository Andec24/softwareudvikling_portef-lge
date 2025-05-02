#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class Character {
protected:
    std::string name;
    int hp;
    int strength;

public:
    Character(const std::string& name, int hp, int strength)
        : name(name), hp(hp), strength(strength) {}

    virtual ~Character() = default;

    const std::string& getName() const { return name; }
    int getHp() const { return hp; }
    int getStrength() const { return strength; }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }

    virtual void attack(Character& target) {
        target.takeDamage(strength);
    }

    virtual void displayStats() const {
        cout << "Name: " << name << ", HP: " << hp << ", Strength: " << strength << endl;
    }
};

#endif // CHARACTER_H
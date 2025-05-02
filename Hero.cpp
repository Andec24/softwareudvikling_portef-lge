#include "Hero.h"

Hero::Hero(const string& name)
    : Character(name, 10, 2), xp(0), level(1) {}

void Hero::gainXp(int amount) {
    xp += amount;
    while (xp >= level * 1000) {
        xp -= level * 1000;
        levelUp();
    }
}

void Hero::levelUp() {
    level++;
    maxHp += 2;
    strength += 1;
    cout << name << " leveled up to level " << level << "!" << endl;
}

void Hero::displayStats() const {
    Character::displayStats();
    cout << "XP: " << xp << ", Level: " << level << endl;
}
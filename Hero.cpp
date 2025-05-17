#include "Hero.h"

Hero::Hero(const string& name)
    : Character(name, 10, 2), xp(0), level(1) {}

void Hero::gainXp(int amount) {
    xp += amount;
    cout << name << " gained " << amount << " XP!" << endl;
    cout << "Current XP: " << xp << endl;
    
    while (xp >= level * 1000) {
        levelUp();
    }
}

void Hero::levelUp() {
    int formerlevel = level;
    level++;
    maxHp += 2;
    strength += 1;
    cout << name << " leveled up to level " << level << "!" << endl;
    cout << "HP increased by 2 and Strength increased by 1!" << endl;
    xp -= formerlevel * 1000;
    cout << "Current XP is now: " << xp << endl;
}

void Hero::displayStats() const {
    Character::displayStats();
    cout << "XP: " << xp << ", Level: " << level << endl;
}

void Hero::obtainGold(int amount) {
    cout << name << "You obtained " << amount << " gold!" << endl;
    gold += amount;

}

int Hero::getLevel() {
    return level;
}


void Hero::equipWeapon(Weapon* weapon) {
    this -> weapon = weapon;
    cout << name << " equipped " << weapon->getName() << "!" << endl;
    
}

Weapon* Hero::getWeapon() const {
    return weapon;
}
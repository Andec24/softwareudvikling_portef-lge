#include "Character.h"

Character::Character(const std::string& name, int hp, int strength)
    : name(name), maxHp(hp), strength(strength){  currentHp = maxHp; }

Character::~Character() = default;

const string& Character::getName() const {
    return name;
}

int Character::getHp() const {
    return currentHp;
}

int Character::getStrength() const {
    return strength;
}

void Character::takeDamage(int damage) {
    currentHp -= damage;
    if (currentHp < 0) currentHp = 0;
}

void Character::resetHp(){
    currentHp = maxHp;
}

void Character::attack(Character& target) {
    int damage = strength;
    Weapon* weapon = getWeapon();
    if (weapon && !weapon->isBroken()){
        damage = weapon->getDamage(strength);
    }
    target.takeDamage(damage);
}

void Character::displayStats() const {
    cout << "Name: " << name << ", HP: " << maxHp << ", Strength: " << strength << endl;
}

Weapon* Character::getWeapon() const {
    return nullptr; // needed for hero class, ignored in enemy class
}
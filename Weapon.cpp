#include "Weapon.h"

Weapon::Weapon(string name, int damage, int strenghtModifier, int durability):
    name(name),
    damage(damage),
    strengthModifier(strenghtModifier),
    durability(durability)
{}

int Weapon::getDamage(int strength) {
        return damage + strengthModifier + strength;
}

string Weapon::getName() {
    return name;
}

Weapon::~Weapon() {}

int Weapon::getWeaponDamage(){
    return damage;
}

int Weapon::getDurability(){
    return durability;
}

int Weapon::getStrengthModifier(){
    return strengthModifier;
}
bool Weapon::isBroken(){
    if (durability <= 0){
        return true;
    }
    else {
        return false;
    }
}

void Weapon::use(){
    durability--;
}


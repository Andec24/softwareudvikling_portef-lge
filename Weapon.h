#ifndef Weapon_H
#define Weapon_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Weapon {
    public:
        Weapon(string name, int damage, int strengthModifier, int durability);
        int getDamage(int strength);
        string getStats();
        bool isBroken();
        void use();
        string getName();
        int getWeaponDamage();
        int getDurability();
        int getStrengthModifier();
        ~Weapon();

       


    private:
        string name;
        int damage;
        int strengthModifier;
        int durability;

};
#endif
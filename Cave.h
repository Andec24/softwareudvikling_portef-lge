#ifndef CAVE_H
#define CAVE_H
#include <iostream>
#include "Enemy.h"
#include "Hero.h"
#include "CombatManager.h"
#include <string>
using namespace std;

class Cave {

private:
    Enemy* enemy1;
    Enemy* enemy2;
    Enemy* enemy3;
    Hero* hero;
    void giveGold();
    string name;

public:
    Cave(Hero & hero);
    void nameCave();
    string getName();
    void enterCave(Hero & hero);
    void createEnemies(Hero & hero);
    void enterCave();
    void fightEnemy(Hero & hero, Enemy & enemy);
    ~Cave();
    

};
#endif
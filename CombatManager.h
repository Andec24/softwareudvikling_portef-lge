#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H
#include "Enemy.h"
#include "Hero.h"
#include "DatabaseManager.h"
#include <iostream>

class CombatManager {
    public:
        CombatManager(Hero& hero, Enemy& enemy);
        void startCombat();
        ~CombatManager();

    protected:
        Hero& hero;
        Enemy& enemy;
        void attack(Character& attacker, Character& defender);
        bool isFightOver();
        void endCombat();
        DatabaseManager db;
        



        
};

#endif
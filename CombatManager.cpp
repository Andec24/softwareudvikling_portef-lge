#include "CombatManager.h"
#include "Hero.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

CombatManager::CombatManager(Hero& hero, Enemy& enemy) : hero(hero), enemy(enemy) {
    cout << "combat started" << endl;
}

void CombatManager::attack(Character& attacker, Character& defender) {
    cout << attacker.getName() << " attacks " << defender.getName() << "!" << endl;
    attacker.attack(defender);
    cout << defender.getName() << " has " << defender.getHp() << " HP left." << endl;
}



void CombatManager::startCombat(){
while (true)
{
    attack(hero, enemy);
    if (enemy.getHp() == 0)
    {break;}
    attack(enemy, hero);
    if (hero.getHp() == 0)
    {break;}

    endCombat();
}
}

void CombatManager::endCombat(){
    if (hero.getHp() == 0){
        cout << "you lost" << endl;
    }
    if (enemy.getHp() == 0){
        cout << "you win" << endl;
        int xpAmount = enemy.giveXpReward();
        hero.gainXp(xpAmount);
        cout << "You gained " << xpAmount << " XP!" << endl;
        cout << "Your current XP: " << hero.getHp() << endl;
        hero.resetHp(); 

    }
}
CombatManager::~CombatManager(){
    cout << "combat ended" << endl;
}


    

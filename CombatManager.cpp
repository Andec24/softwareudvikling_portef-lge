#include "CombatManager.h"
#include "Hero.h"
#include "Enemy.h"
#include <iostream>
#include <unistd.h>
using namespace std;

CombatManager::CombatManager(Hero& hero, Enemy& enemy) : hero(hero), enemy(enemy) {
}

void CombatManager::attack(Character& attacker, Character& defender) {
   
    cout << attacker.getName() << " attacks " << defender.getName() << "!" << endl;
    attacker.attack(defender);
    cout << defender.getName() << " has " << defender.getHp() << " HP left." << endl;

}



void CombatManager::startCombat(){
    cout << "you are fighting a: " << enemy.getName() << endl;
    cout << "Combat started!" << endl;
    enemy.displayStats();
    hero.displayStats();
    


while (true)
{
    sleep(1);
    attack(hero, enemy);
    if (enemy.getHp() == 0)
    {break;}
    sleep(1);
    attack(enemy, hero);
    if (hero.getHp() == 0)
    {break;}
    cout << endl;

    
}
endCombat();
}

void CombatManager::endCombat(){
    if (hero.getHp() == 0){
        cout << "GAME OVER!!!" << endl;
        exit(0);
    }
    if (enemy.getHp() == 0){
        cout << endl;
        cout << "YOU WIN!" << endl;
        int xpAmount = enemy.giveXpReward();
        hero.gainXp(xpAmount);
        hero.resetHp(); 
        enemy.resetHp();

    }
}
CombatManager::~CombatManager(){
    cout << "combat ended" << endl;
    cout << endl;
    
    
}


    

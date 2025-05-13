#include "Cave.h"



using namespace std;


Cave::Cave(Hero & hero){
    this-> hero = &hero;
    nameCave(); // Call the function to name the cave

}

void Cave::nameCave() {
        int nameNumber = rand() % 6 + 1; // Generates a random number between 1 and 6

        if(nameNumber == 1) {
            name = "Cave of Shadows";
        } else if(nameNumber == 2) {
            name = "Cave of Echoes";
        } else if(nameNumber == 3) {
            name = "Cave of Whispers";
        } else if(nameNumber == 4) {
            name = "Cave of Secrets";
        } else if(nameNumber == 5) {
            name = "Cave of Illusions";
        } else if(nameNumber == 6) {
            name = "Cave of Nightmares";
        }


}

string Cave::getName() {
    return name;
}  

void Cave::createEnemies(Hero & hero) {
    int enemy1Strenght = hero.getStrength() - rand() % 4;
    int enemy1Hp = hero.getHp() - rand() % 4;
    int enemy1Xp = hero.getLevel() * 100;
    enemy1 = new Enemy("weak Goblin", enemy1Hp, enemy1Strenght, enemy1Xp);

    int enemy2Strenght = hero.getStrength() - rand() % 2;
    int enemy2Hp = hero.getHp() - rand() % 2;
    int enemy2Xp = hero.getLevel() * 200;
    enemy2 = new Enemy("Goblin", enemy2Hp, enemy2Strenght, enemy2Xp);

    int enemy3Strenght = hero.getStrength();
    int winDecider = rand() % 1 + 20;
    if (winDecider == 1) {
        enemy3Strenght = hero.getStrength() + rand() % 2;
    } else {
        enemy3Strenght = hero.getStrength();
    }
    int enemy3Hp = hero.getHp();
    int enemy3Xp = hero.getLevel() * 300;
    enemy3 = new Enemy("Zombie", enemy3Hp, enemy3Strenght, enemy3Xp);
       
}

void Cave::enterCave(Hero & hero) {
    cout << "You have entered the cave." << endl;
    createEnemies(hero);
    fightEnemy(hero, *enemy1);
    fightEnemy(hero, *enemy2);
    fightEnemy(hero, *enemy3);
    cout << "You have defeated all enemies in the cave!" << endl;
    giveGold();
}

void Cave::fightEnemy(Hero & hero, Enemy & enemy) {
    CombatManager combatManager(hero, enemy);
    combatManager.startCombat();
}
void Cave::giveGold() {
    int goldAmount = random() % 50 + 100;
    hero->obtainGold(goldAmount);
}

Cave::~Cave() {
    delete enemy1;
    delete enemy2;
    delete enemy3;   
}
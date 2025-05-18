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
    giveRewards();
}

void Cave::fightEnemy(Hero & hero, Enemy & enemy) {
    CombatManager combatManager(hero, enemy);
    combatManager.startCombat();
}
void Cave::giveRewards() {
    int goldAmount = random() % 100 + 50;
    hero->obtainGold(goldAmount);

    Weapon * weapon = generateWeapon();
    cout << "You found a " << weapon->getName() << "!" << endl;
    if (hero->getWeapon() == nullptr) {
        cout << "You have no weapon equipped. Equipping the new weapon." << endl;
        hero->equipWeapon(weapon);
        return;
    }
    
    cout << "Your current weapon is: " << hero->getWeapon()->getName() << endl;
    cout << "do you want to equip the new weapon? (y/n): ";
    string choice;
    cin >> choice;
    if (choice == "y") {
        hero->equipWeapon(weapon);
    } else {
        cout << "You chose not to equip the new weapon." << endl;
        delete weapon; // deletes object if not equipped
    }
    
}

Weapon* Cave::generateWeapon() {
    int weaponType = rand() % 6 + 1;
    if (weaponType == 1) {
        return new Weapon("Sword", 5, 2, 25);
    } else if (weaponType == 2) {
        return new Weapon("Axe", 7, 3, 12);
    } else if (weaponType == 3) {
        return new Weapon("Bow", 4, 1, 20);
    }
    else if (weaponType == 4) {
        return new Weapon("Spear", 6, 2, 15);
    }
    else if (weaponType == 5) {
        return new Weapon("Dagger", 3, 1, 30);
    }
    else {
        return new Weapon("Staff", 4, 2, 10);
    }
    
}

Cave::~Cave() {
    delete enemy1;
    delete enemy2;
    delete enemy3;   
}
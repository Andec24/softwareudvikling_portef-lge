#include <iostream>
#include <string>
#include "Hero.h"
#include "Enemy.h"
#include "CombatManager.h"
using namespace std;

// Enemy instances
Enemy Goblin("Goblin", 10, 2, 250);
Enemy Zombie("Zombie", 15, 3, 300);
Enemy Orc("Orc", 20, 4, 500);
Enemy Troll("Troll", 30, 6, 600);
Enemy Vampire("Vampire", 40, 8, 800);
Enemy Dragon("Dragon", 50, 10, 1000);

void fightDecider(Hero& hero);  // Forward declaration
void decider(Hero& hero);


// Starts a fight between the hero and the chosen enemy
void startFight(Hero& hero, Enemy& enemy) {
    CombatManager combatManager(hero, enemy);
    combatManager.startCombat();
}

// Prompts user to create or select a hero
Hero gameStart() {
    string heroName;
    cout << "Play with Arthur (1), enter your own name (2) or quit (3): ";
    string choice;
    cin >> choice;

    if (choice == "1") {
        heroName = "Arthur";
    } else if (choice == "2") {
        cout << "Enter your hero's name: ";
        cin >> heroName;
    } else {
        cout << "Invalid choice. Defaulting to Arthur." << endl;
        heroName = "Arthur";
    }

    Hero player(heroName);
    return player;
}

// Handles user decision to continue or quit
void decider(Hero& hero) {
    cout << "Your options are:" << endl;
    cout << "Fight enemy (1) or quit (2): ";
    string choice;
    cin >> choice;

    if (choice == "1") {
        fightDecider(hero);
    } else if (choice == "2") {
        cout << "Exiting the game." << endl;
        exit(0);
    } else {
        cout << "Invalid choice. Please try again." << endl;
        decider(hero);
    }
}

// Lets the user pick an enemy to fight
void fightDecider(Hero& hero) {
    cout << "Choose an enemy to fight:" << endl;
    cout << "1. Goblin" << endl;
    cout << "2. Orc" << endl;
    cout << "3. Zombie" << endl;
    cout << "4. Troll" << endl;
    cout << "5. Vampire" << endl;
    cout << "6. Dragon" << endl;

    string choice;
    cin >> choice;

    if (choice == "1") {
        startFight(hero, Goblin);
    } else if (choice == "2") {
        startFight(hero, Orc);
    } else if (choice == "3") {
        startFight(hero, Zombie);
    } else if (choice == "4") {
        startFight(hero, Troll);
    } else if (choice == "5") {
        startFight(hero, Vampire);
    } else if (choice == "6") {
        startFight(hero, Dragon);
    } else {
        cout << "Invalid choice. Please try again." << endl;
        fightDecider(hero);
    }
}

// Main game loop
int main() {
    Hero player = gameStart();
    cout << "Welcome to the game, " << player.getName() << "!" << endl;
    cout << "You have " << player.getHp() << " HP and " << player.getStrength() << " strength." << endl;

    while (true) {
        decider(player);
    }
}

#include <iostream>
#include <string>
#include <optional>
#include "Hero.h"
#include "Enemy.h"
#include "CombatManager.h"
#include "Cave.h"
#include "DatabaseManager.h"
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
void analysisMenu(DatabaseManager& db);


// Starts a fight between the hero and the chosen enemy
void startFight(Hero& hero, Enemy& enemy) {
    CombatManager combatManager(hero, enemy);
    combatManager.startCombat();
}

// Prompts user to create or select a hero
Hero gameStart(DatabaseManager& db) {
    string heroName;
    cout << "Load a Hero (1), Create new Hero (2), Analyse Game (3), or Quit (4): ";
    string choice;
    cin >> choice;

    if (choice == "1") {
        cout << "Enter hero name to load: ";
        cin >> heroName;
        auto loadedHero = db.loadHero(heroName);
        if (loadedHero) {
            cout << "Hero loaded successfully!" << endl;
            return *loadedHero;
        } else {
            cout << "Hero not found. Creating a new one." << endl;
        }
    } else if (choice == "2") {
        cout << "Enter your hero's name: ";
        cin >> heroName;
        return Hero(heroName,1, 0, 0);
    } else if (choice == "3") {
        analysisMenu(db);
        return gameStart(db);
    } else {
        cout << "Quitting game." << endl;
        exit(0);
    }

    return Hero("Arthur", 1, 0, 0); // Default hero if none is created
}

void analysisMenu(DatabaseManager& db) {
    cout << "\n--- Game Analysis Menu ---\n";
    cout << "1. Show all heroes alphabetically\n";
    cout << "2. Show total monsters defeated per hero\n";
    cout << "3. Show weapon kills by specific hero\n";
    cout << "4. Show top hero per weapon\n";
    cout << "5. Return to main menu\n";

    string choice;
    cin >> choice;
    if (choice == "1") db.showAllHeroesAlphabetically();
    else if (choice == "2") db.showMonsterKillsPerHero();
    else if (choice == "3") {
        cout << "Enter hero name: ";
        string heroName;
        cin >> heroName;
        db.showWeaponKillsByHero(heroName);
    }
    else if (choice == "4") db.showHeroMostKillsPerWeapon();
    else return;

    analysisMenu(db); // Loop until user chooses to return
}

// Handles user decision to continue or quit
void decider(Hero& hero) {
    cout << "Your options are:" << endl;
    cout << "Fight enemy (1), enter cave (2), save hero(3) or quit (4): ";
    string choice;
    cin >> choice;

    if (choice == "1") {
        fightDecider(hero);
    } else if (choice == "2") {
        Cave cave(hero);
        cout << "You have entered the "<< cave.getName() << endl;
        cave.enterCave(hero);
    } else if (choice == "3") {
        DatabaseManager db;
        db.saveHero(hero.getName(), hero.getLevel(), hero.getXp(), hero.getGold());
        cout << "Hero saved successfully!" << endl;

    } else if (choice == "4") {
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
    DatabaseManager db;
    Hero player = gameStart(db);
    cout << "Welcome to the game, " << player.getName() << "!" << endl;
    cout << "You have " << player.getHp() << " HP and " << player.getStrength() << " strength." << endl;

    while (true) {
        decider(player);
    }
}

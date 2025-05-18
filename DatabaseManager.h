// DatabaseManager.h
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <sqlite3.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <optional>
#include "Hero.h"
#include <tuple>

using namespace std;

class DatabaseManager {
public:
    DatabaseManager(const string& dbFile = "game.db");
    ~DatabaseManager();

    void initTables();

    // Save/load heroes
    void saveHero(const string& name, int level, int xp, int gold);
    optional<Hero> loadHero(const string& name);

    // Log combat outcomes
    void logKill(const string& heroName, const string& weaponName, const string& monsterName);

    // Query functions for game analysis
    void showAllHeroesAlphabetically();
    void showMonsterKillsPerHero();
    void showWeaponKillsByHero(const string& heroName);
    void showHeroMostKillsPerWeapon();

private:
    sqlite3* db;
};

#endif

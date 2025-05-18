// DatabaseManager.cpp
#include "DatabaseManager.h"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& dbFile) {
    if (sqlite3_open(dbFile.c_str(), &db)) {
        std::cerr << "[SQLite] Failed to open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    } else {
        initTables();
    }
}

DatabaseManager::~DatabaseManager() {
    if (db) sqlite3_close(db);
}

void DatabaseManager::initTables() {
    const char* heroTable =
        "CREATE TABLE IF NOT EXISTS Heroes ("
        "name TEXT PRIMARY KEY,"
        "level INTEGER,"
        "xp INTEGER,"
        "gold INTEGER);";

    const char* killsTable =
        "CREATE TABLE IF NOT EXISTS MonsterKills ("
        "hero_name TEXT,"
        "weapon_name TEXT,"
        "monster_name TEXT,"
        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);";

    char* errMsg = nullptr;
    sqlite3_exec(db, heroTable, nullptr, nullptr, &errMsg);
    sqlite3_exec(db, killsTable, nullptr, nullptr, &errMsg);
}

void DatabaseManager::saveHero(const string& name, int level, int xp, int gold) {
    std::string sql = "INSERT OR REPLACE INTO Heroes (name, level, xp, gold) VALUES ('" +
                      name + "', " + 
                      to_string(level) + ", " + 
                      to_string(xp) + ", " + 
                      to_string(gold) + ");";
    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

optional<Hero> DatabaseManager::loadHero(const string& name) {
    string sql = "SELECT level, xp, gold FROM Heroes WHERE name='" + name + "';";
    tuple<int, int, int> tupleData = {0, 0, 0}; // level, xp, gold
    bool found = false;

    sqlite3_exec(db, sql.c_str(), [](void* data, int argc, char** argv, char**) -> int {
        auto* output = static_cast<tuple<int, int, int>*>(data);
        get<0>(*output) = stoi(argv[0]);
        get<1>(*output) = stoi(argv[1]);
        get<2>(*output) = stoi(argv[2]);
        return 0;
    }, &tupleData, nullptr);

    int level = get<0>(tupleData);
    int xp = get<1>(tupleData);
    int gold = get<2>(tupleData);

    if (level > 0) {
        return Hero(name, level, xp, gold);
    } else {
        return nullopt;
    }
}


void DatabaseManager::logKill(const string& heroName, const string& weaponName, const string& monsterName) {
    string sql = "INSERT INTO MonsterKills (hero_name, weapon_name, monster_name) VALUES ('" +
          heroName + "', '" + weaponName + "', '" + monsterName + "');";
    sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
}

void DatabaseManager::showAllHeroesAlphabetically() {
    cout << "Heroes (alphabetically):\n";
    const char* sql = "SELECT name FROM Heroes ORDER BY name;";
    sqlite3_exec(db, sql, [](void*, int argc, char** argv, char**) -> int {
        cout << " - " << argv[0] << endl;
        return 0;
    }, nullptr, nullptr);
}

void DatabaseManager::showMonsterKillsPerHero() {
    cout << "Monsters defeated per hero:\n";
    const char* sql = "SELECT hero_name, COUNT(*) FROM MonsterKills GROUP BY hero_name;";
    sqlite3_exec(db, sql, [](void*, int argc, char** argv, char**) -> int {
        cout << argv[0] << ": " << argv[1] << " monsters\n";
        return 0;
    }, nullptr, nullptr);
}

void DatabaseManager::showWeaponKillsByHero(const string& heroName) {
    cout << "Monsters defeated by " << heroName << " per weapon:\n";
    string sql = "SELECT weapon_name, COUNT(*) FROM MonsterKills WHERE hero_name='" + heroName + "' GROUP BY weapon_name;";
    sqlite3_exec(db, sql.c_str(), [](void*, int argc, char** argv, char**) -> int {
        cout << " - " << argv[0] << ": " << argv[1] << " kills\n";
        return 0;
    }, nullptr, nullptr);
}

void DatabaseManager::showHeroMostKillsPerWeapon() {
    cout << "Top hero per weapon:\n";
    const char* sql = R"(
        SELECT weapon_name, hero_name, COUNT(*) as kills
        FROM MonsterKills
        GROUP BY weapon_name, hero_name
        HAVING kills = (
            SELECT MAX(k) FROM (
                SELECT COUNT(*) as k
                FROM MonsterKills as sub
                WHERE sub.weapon_name = MonsterKills.weapon_name
                GROUP BY sub.hero_name
            )
        );
    )";
    sqlite3_exec(db, sql, [](void*, int argc, char** argv, char**) -> int {
        cout << argv[0] << " - " << argv[1] << ": " << argv[2] << " kills\n";
        return 0;
    }, nullptr, nullptr);
}

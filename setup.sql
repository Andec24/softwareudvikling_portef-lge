-- setup.sql

DROP TABLE IF EXISTS Heroes;
DROP TABLE IF EXISTS MonsterKills;

CREATE TABLE Heroes (
    name TEXT PRIMARY KEY,
    level INTEGER,
    xp INTEGER,
    gold INTEGER
);

CREATE TABLE MonsterKills (
    hero_name TEXT,
    weapon_name TEXT,
    monster_name TEXT,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);

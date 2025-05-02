#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
private:
    int xpReward;

public:
    Enemy(const std::string& name, int hp, int strength, int xpReward);
    int giveXpReward() const;
    void displayStats() const override;
};

#endif // ENEMY_H
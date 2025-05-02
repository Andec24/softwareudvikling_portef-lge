#include "Enemy.h"

Enemy::Enemy(const std::string& name, int hp, int strength, int xpReward)
    : Character(name, hp, strength), xpReward(xpReward) {}

int Enemy::giveXpReward() const {
    return xpReward;
}

void Enemy::displayStats() const {
    Character::displayStats();
    std::cout << "XP Reward: " << xpReward << std::endl;
}
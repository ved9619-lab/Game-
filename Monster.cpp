//
// Created by Vedant Pawar on 17/03/2024.
//
#include "Monster.hpp"

Monster::Monster(const std::string& name, int health) : name(name), health(health) {}

const std::string& Monster::GetName() const {
    return name;
}

int Monster::GetHealth() const {
    return health;
}

void Monster::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

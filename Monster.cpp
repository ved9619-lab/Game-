#include "Monster.hpp"

Monster::Monster(const std::string& name, int health) : name(name), health(health) {}

void Monster::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

int Monster::Attack() {
    // Simple attack example, you can customize this
    return 5; // Monster deals 5 damage per attack
}

int Monster::GetHealth() const {
    return health;
}

const std::string& Monster::GetName() const {
    return name;
}

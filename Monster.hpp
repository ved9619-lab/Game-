#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>

class Monster {
private:
    std::string name;
    int health;

public:
    Monster(const std::string& name, int health);

    void TakeDamage(int damage);
    int Attack(); // Returns the amount of damage the monster deals
    int GetHealth() const;
    const std::string& GetName() const;
};

#endif // MONSTER_HPP

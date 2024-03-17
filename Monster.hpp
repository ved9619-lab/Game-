#ifndef MONSTER_HPP
#define MONSTER_HPP

#include <string>

class Monster {
public:
    Monster(const std::string& name, int health);

    const std::string& GetName() const;
    int GetHealth() const;
    void TakeDamage(int damage);

private:
    std::string name;
    int health;
};

#endif // MONSTER_HPP

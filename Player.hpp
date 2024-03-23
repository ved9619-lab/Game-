#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Room.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include <vector>
#include <string>

class Player {
private:
    std::string name;
    Room* location;
    int health;
    std::vector<Item> inventory;

public:
    Player(const std::string& name, const std::string& difficulty);

    void move(const std::string& direction, Room* treasureRoom);
    void pickUpItem(const std::string& itemName);
    void dropItem(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;
    void lookAround() const;
    void Hit(Monster* monster);
    void SpecialAbility();
    int RollDice() const;
    Room* GetLocation() const;
    void SetLocation(Room* newLocation);
    int GetHealth() const;
    void SetHealth(int newHealth);
    void DisplayHealthBar() const;
};

#endif // PLAYER_HPP

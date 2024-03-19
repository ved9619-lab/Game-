#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Room.hpp"
#include "Item.hpp"
#include "Monster.hpp"

class Player {
private:
    std::string name;
    int health;
    Room* location;
    std::vector<Item> inventory;

public:
    Player(const std::string& name, int health);

    void move(const std::string& direction, Room* treasureRoom);
    void pickUpItem(const std::string& itemName);
    void dropItem(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;
    void lookAround() const;
    void Hit(Monster* monster);
    int RollDice() const;
    Room* GetLocation() const;
    void SetLocation(Room* newLocation);
    int GetHealth() const;
};

#endif

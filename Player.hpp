#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Item.hpp"
#include "Room.hpp"

class Player {
private:
    std::string name;
    int health;
    Room* location;
    std::vector<Item> inventory;

public:
    Player(const std::string& name, const std::string& difficulty); // Updated constructor

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

#endif // PLAYER_HPP

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Room.hpp"
#include "Item.hpp"

class Player {
public:
    Player(const std::string& name, int health);
    void move(const std::string& direction);
    void pickUpItem(const std::string& itemName);
    void lookAround();
    Room* GetLocation();
    void SetLocation(Room* room);
    void AddItemToInventory(const Item& item);
    bool RemoveItemFromInventory(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;

private:
    std::string name;
    int health;
    Room* location;
    std::vector<Item> inventory;
};

#endif // PLAYER_HPP

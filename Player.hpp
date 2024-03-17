#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Room.hpp"
#include "Item.hpp"
#include <vector>

class Player {
private:
    std::string name;
    int health;
    Room* location;
    std::vector<Item> inventory;

public:
    Player(const std::string& name, int health);
    void move(const std::string& direction);
    void pickUpItem(const std::string& item);
    void lookAround();
    void dropItem(const std::string& itemName);
    Room* GetLocation();
    void SetLocation(Room* room);
    void AddItemToInventory(const Item& item);
    bool RemoveItemFromInventory(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;
};

#endif


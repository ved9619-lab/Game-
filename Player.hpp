#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Character.hpp"
#include "Room.hpp"
#include "Item.hpp"
#include <vector>

class Player : public Character {
public:
    Player(const std::string& name, int health);

    Room* GetLocation();
    void SetLocation(Room* room);

    void AddItemToInventory(const Item& item);
    bool RemoveItemFromInventory(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;

private:
    Room* location;
    std::vector<Item> inventory;
};

#endif // PLAYER_HPP

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include <map>  // Include for std::map
#include "Item.hpp"
#include "Monster.hpp"

class Room {
public:
    Room(const std::string& desc);

    const std::string& GetDescription() const;
    Room* GetExit(const std::string& direction);
    void AddExit(const std::string& direction, Room* room);
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    const std::vector<Item>& GetItems() const;

    // Monster methods
    const Monster* GetMonster() const;
    void SetMonster(Monster* monster);
    bool HasMonster() const;
    void RemoveMonster();

private:
    std::string description;
    std::vector<Item> items;
    std::map<std::string, Room*> exits;
    Monster* monster; // Pointer to a Monster object
};

#endif // ROOM_HPP

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Item.hpp"
#include "Monster.hpp"

#include <string>
#include <vector>
#include <map>

class Room {
public:
    Room(const std::string& desc);

    const std::string& GetDescription() const;
    Room* GetExit(const std::string& direction);
    void AddExit(const std::string& direction, Room* room);
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    const std::vector<Item>& GetItems() const;

    Monster* GetMonster();
    void SetMonster(Monster* monster);
    bool HasMonster();

private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;
    Monster* monster; // Monster in the room
};

#endif

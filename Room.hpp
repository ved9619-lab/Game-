#ifndef COURSEWORK_C___ROOM_HPP
#define COURSEWORK_C___ROOM_HPP

#include <string>
#include <map>
#include <vector>
#include "Item.hpp"  // Include the Item class

class Room {
private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;  // Items in the room

public:
    explicit Room(const std::string& desc);
    const std::string& GetDescription() const;
    Room* GetExit(const std::string& direction);
    void AddExit(const std::string& direction, Room* room);
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName); // Declaration of RemoveItem
    const std::vector<Item>& GetItems() const;
};

#endif // COURSEWORK_C___ROOM_HPP

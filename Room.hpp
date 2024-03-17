#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <vector>
#include "Item.hpp"
#include <map>  // Include map from standard library

class Room {
public:
    Room(const std::string& desc);

    const std::string& GetDescription() const;

    Room* GetExit(const std::string& direction);

    void AddExit(const std::string& direction, Room* room);

    void AddItem(const Item& item);

    void RemoveItem(const std::string& itemName);

    const std::vector<Item>& GetItems() const;

private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;
};

#endif /* ROOM_HPP */


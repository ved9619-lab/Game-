//
// Created by Vedant Pawar on 11/03/2024.
//

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
    std::vector<Item> items;

public:
    Room(const std::string& desc);
    void AddExit(const std::string& direction, Room* room);

    std::vector<Item>& GetItems();
    const std::string& GetDescription() const;
    Room* GetExit(const std::string& direction);
    void AddItem(const Item& item);
};


#endif //COURSEWORK_C___ROOM_HPP

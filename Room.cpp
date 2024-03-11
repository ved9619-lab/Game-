//
// Created by Vedant Pawar on 11/03/2024.
//

#include "Room.hpp"
#include "Item.hpp"  // Include the actual definition of Item class

Room::Room(const std::string& desc) : description(desc) {}

void Room::AddExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

std::vector<Item>& Room::GetItems() {
    return items;
}

const std::string& Room::GetDescription() const {
    return description;
}

Room* Room::GetExit(const std::string& direction) {
    if (exits.count(direction) > 0) {
        return exits[direction];
    } else {
        return nullptr;
    }
}

void Room::AddItem(const Item& item) {
    items.push_back(item);
}


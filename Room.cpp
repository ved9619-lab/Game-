#include "Room.hpp"

Room::Room(const std::string& desc) : description(desc) {}

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

void Room::AddExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

void Room::AddItem(const Item& item) {
    items.push_back(item);
}

void Room::RemoveItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->GetName() == itemName) {
            items.erase(it);
            break;
        }
    }
}

const std::vector<Item>& Room::GetItems() const {
    return items;
}

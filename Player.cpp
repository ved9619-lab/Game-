#include "Player.hpp"
#include "Room.hpp"

Player::Player(const std::string& name, int health) : Character(name, health), location(nullptr) {}

Room* Player::GetLocation() {
    return location;
}

void Player::SetLocation(Room* room) {
    location = room;
}

void Player::AddItemToInventory(const Item& item) {
    inventory.push_back(item);
}

bool Player::RemoveItemFromInventory(const std::string& itemName) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&itemName](const Item& item) {
        return item.GetName() == itemName;
    });

    if (it != inventory.end()) {
        inventory.erase(it);
        return true;
    }

    return false;
}

const std::vector<Item>& Player::GetInventory() const {
    return inventory;
}

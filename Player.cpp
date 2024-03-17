#include "Player.hpp"
#include <iostream>

Player::Player(const std::string& name, int health) : name(name), health(health), location(nullptr) {}

void Player::move(const std::string& direction) {
    // Implement movement logic
    if (location != nullptr) {
        Room* nextRoom = location->GetExit(direction);
        if (nextRoom != nullptr) {
            location = nextRoom;
            std::cout << "Player moves " << direction << "." << std::endl;
        } else {
            std::cout << "Cannot move " << direction << ". No path in that direction." << std::endl;
        }
    } else {
        std::cout << "Player is not in a valid room." << std::endl;
    }
}

void Player::pickUpItem(const std::string& itemName) {
    if (location != nullptr) {
        const std::vector<Item>& roomItems = location->GetItems();
        auto it = std::find_if(roomItems.begin(), roomItems.end(), [&](const Item& item) {
            return item.GetName() == itemName;
        });

        if (it != roomItems.end()) {
            Item item = *it;
            AddItemToInventory(item);
            location->RemoveItem(itemName);
            std::cout << "Player picks up " << itemName << "." << std::endl;
        } else {
            std::cout << "Item '" << itemName << "' not found in this room." << std::endl;
        }
    } else {
        std::cout << "Player is not in a valid room." << std::endl;
    }
}

void Player::lookAround() {
    // Implement look around logic
    if (location != nullptr) {
        std::cout << "Current Location: " << location->GetDescription() << std::endl;
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : location->GetItems()) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
        }
        std::cout << "Inventory:" << std::endl;
        for (const Item& item : inventory) {
            std::cout << "- " << item.GetName() << std::endl;
        }
    } else {
        std::cout << "Player is not in a valid room." << std::endl;
    }
}

void Player::dropItem(const std::string& itemName) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](const Item& item) {
        return item.GetName() == itemName;
    });

    if (it != inventory.end()) {
        location->AddItem(*it);
        inventory.erase(it);
        std::cout << "Player drops " << itemName << "." << std::endl;
    } else {
        std::cout << "Item '" << itemName << "' not found in inventory." << std::endl;
    }
}

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
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](const Item& item) {
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

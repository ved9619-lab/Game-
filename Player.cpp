#include "Player.hpp"

#include <iostream>

Player::Player(const std::string& name, int health) : name(name), health(health), location(nullptr) {}

void Player::move(const std::string& direction) {
    Room* nextRoom = location->GetExit(direction);
    if (nextRoom != nullptr) {
        location = nextRoom;
        std::cout << "Player moves " << direction << "." << std::endl;
    } else {
        std::cout << "Cannot move in that direction." << std::endl;
    }
}

void Player::pickUpItem(const std::string& itemName) {
    const std::vector<Item>& roomItems = location->GetItems();
    for (const Item& item : roomItems) {
        if (item.GetName() == itemName) {
            inventory.push_back(item);
            location->RemoveItem(itemName);
            std::cout << "Picked up " << itemName << "." << std::endl;
            return;
        }
    }
    std::cout << "Item '" << itemName << "' not found in this room." << std::endl;
}

void Player::dropItem(const std::string& itemName) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->GetName() == itemName) {
            location->AddItem(*it);
            inventory.erase(it);
            std::cout << "Dropped " << itemName << "." << std::endl;
            return;
        }
    }
    std::cout << "Item '" << itemName << "' not found in inventory." << std::endl;
}

const std::vector<Item>& Player::GetInventory() const {
    return inventory;
}

void Player::lookAround() const {
    std::cout << "Current Location: " << location->GetDescription() << std::endl;
    std::cout << "Items in the room:" << std::endl;
    for (const Item& item : location->GetItems()) {
        std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
    }
}

void Player::Hit(Monster* monster) {
    // Player attacks the monster
    int playerDamage = RollDice();
    std::cout << "You hit the " << monster->GetName() << " for " << playerDamage << " damage." << std::endl;
    monster->TakeDamage(playerDamage);

    // Check if the monster is defeated
    if (monster->GetHealth() <= 0) {
        std::cout << "You have defeated the " << monster->GetName() << "!" << std::endl;
        location->SetMonster(nullptr); // Remove the monster from the room
        return;
    }

    // Monster attacks the player
    int monsterDamage = monster->Attack();
    std::cout << "The " << monster->GetName() << " hits you for " << monsterDamage << " damage." << std::endl;
    health -= monsterDamage;

    if (health <= 0) {
        std::cout << "You have been defeated by the " << monster->GetName() << "!" << std::endl;
        // Game over logic here
    }
}

int Player::RollDice() const {
    // Simplified dice rolling, returns a random value between 1 and 10
    return rand() % 10 + 1;
}

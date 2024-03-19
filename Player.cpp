#include "Player.hpp"
#include "Monster.hpp" // Include Monster.hpp

#include <iostream>

Player::Player(const std::string& name, const std::string& difficulty) : name(name), location(nullptr) {
    // Set player health based on difficulty
    if (difficulty == "easy") {
        health = 100;
    } else if (difficulty == "medium") {
        health = 80;
    } else if (difficulty == "difficult") {
        health = 60;
    } else {
        std::cerr << "Invalid difficulty level! Setting health to default (100)." << std::endl;
        health = 100;
    }
}

void Player::move(const std::string& direction, Room* treasureRoom) {
    Room* nextRoom = location->GetExit(direction);
    if (nextRoom != nullptr) {
        if (nextRoom == treasureRoom) {
            bool hasKey = false;
            for (const Item& item : inventory) {
                if (item.GetName() == "heavy key") {
                    hasKey = true;
                    break;
                }
            }
            if (!hasKey) {
                std::cout << "You need the heavy key to enter this room!" << std::endl;
                return;
            }
        }
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

    // Check if player has a sword in inventory
    bool hasSword = false;
    for (const Item& item : inventory) {
        if (item.GetName() == "sword") {
            hasSword = true;
            break;
        }
    }

    if (hasSword) {
        // If player has sword, increase damage
        std::cout << "You hit the " << monster->GetName() << " with your sword for " << playerDamage * 4 << " damage." << std::endl;
        playerDamage *= 4; // Quadruple damage with sword (40 damage)
    } else {
        std::cout << "You hit the " << monster->GetName() << " for " << playerDamage << " damage." << std::endl;
    }

    monster->TakeDamage(playerDamage);

    // Check if the monster is defeated
    if (monster->GetHealth() <= 0) {
        std::cout << "You have defeated the " << monster->GetName() << "!" << std::endl;
        location->SetMonster(nullptr); // Remove the monster from the room

        // Create a heavy key item if the defeated monster is the dragon
        if (monster->GetName() == "Dragon") {
            Item heavyKey("heavy key", "A heavy key that looks important.");
            location->AddItem(heavyKey);
            std::cout << "You found a Heavy Key!" << std::endl;
        }

        return;
    }

    // Monster attacks the player
    int monsterDamage = monster->Attack();
    std::cout << "The " << monster->GetName() << " hits you for " << monsterDamage << " damage." << std::endl;
    health -= monsterDamage;

    // Check if the player is defeated
    if (health <= 0) {
        std::cout << "You have been defeated by the " << monster->GetName() << "!" << std::endl;
        // Game over logic here
    }
}

int Player::RollDice() const {
    // Simplified dice rolling, returns a random value between 1 and 10
    return rand() % 10 + 1;
}

Room* Player::GetLocation() const {
    return location;
}

void Player::SetLocation(Room* newLocation) {
    location = newLocation;
}

int Player::GetHealth() const {
    return health;
}

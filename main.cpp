#include <iostream>
#include <string>
#include "Area.hpp"
#include "Player.hpp"
#include "Item.hpp"

std::string gameMapFilePath = "/Users/vedantpawar/CLionProjects/Coursework C++/game_map.txt";

int main() {
    // Create an Area
    Area gameWorld;

    // Load the game map from the file
    gameWorld.LoadMapFromFile(gameMapFilePath);

    // Create Items
    Item torch("torch", "A torch providing a flickering light.");
    Item key("key", "A heavy key that looks important.");
    Item map("map", "An old map showing hidden passages.");

    // Get the rooms
    auto startRoom = gameWorld.GetRoom("startRoom");
    auto hallway = gameWorld.GetRoom("hallway");
    auto treasureRoom = gameWorld.GetRoom("treasureRoom");
    auto secretRoom = gameWorld.GetRoom("secretRoom");
    auto bossRoom = gameWorld.GetRoom("bossRoom");

    // Check if the rooms exist before adding items
    if (startRoom != nullptr) {
        startRoom->AddItem(torch);
    }

    if (treasureRoom != nullptr) {
        treasureRoom->AddItem(key);
    }

    if (secretRoom != nullptr) {
        secretRoom->AddItem(map);
    }

    // Create a Player
    Player player("Alice", 100);

    // Set the player's starting location
    player.SetLocation(startRoom);

    // Game loop (basic interaction)
    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;

        // Display items in the room
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
        }

        // Display inventory items
        std::cout << "Inventory:" << std::endl;
        for (const Item& item : player.GetInventory()) {
            std::cout << "- " << item.GetName() << std::endl;
        }

        // Display options
        std::cout << "Options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Pick up an item | ";
        std::cout << "3. Drop an item | ";
        std::cout << "4. Move to another room | ";
        std::cout << "5. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // Player looks around (no action required)
            std::cout << "You look around the room." << std::endl;
        } else if (choice == 2) {
            // Player picks up an item in the room
            std::cout << "Enter the name of the item you want to pick up: ";
            std::string itemName;
            std::cin >> itemName;
            for (const Item& item : player.GetLocation()->GetItems()) {
                if (item.GetName() == itemName) {
                    player.AddItemToInventory(item);
                    player.GetLocation()->RemoveItem(itemName);
                    std::cout << "You picked up " << itemName << "." << std::endl;
                    break;
                }
            }
        } else if (choice == 3) {
            // Player drops an item from inventory
            std::cout << "Enter the name of the item you want to drop: ";
            std::string itemName;
            std::cin >> itemName;
            if (player.RemoveItemFromInventory(itemName)) {
                player.GetLocation()->AddItem(Item(itemName, "An item."));
                std::cout << "You dropped " << itemName << "." << std::endl;
            } else {
                std::cout << "Item not found in inventory." << std::endl;
            }
        } else if (choice == 4) {
            // Player moves to another room
            std::cout << "Enter the direction (e.g., north, south, east, west): ";
            std::string direction;
            std::cin >> direction;

            Room* nextRoom = player.GetLocation()->GetExit(direction);
            if (nextRoom != nullptr) {
                player.SetLocation(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            } else {
                std::cout << "You can't go that way." << std::endl;
            }
        } else if (choice == 5) {
            // Quit the game
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}

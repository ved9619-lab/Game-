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

    // Debugging: Print out the names of rooms in the game world
    std::cout << "Rooms in the game world:" << std::endl;
    for (const auto& pair : gameWorld.GetRooms()) {
        std::cout << "- " << pair.first << std::endl;
    }

    // Create Items
    Item key("Key", "A shiny key that looks important.");
    Item sword("Sword", "A sharp sword with a golden hilt.");

    // Get the rooms
    auto startRoom = gameWorld.GetRoom("startRoom");
    auto treasureRoom = gameWorld.GetRoom("treasureRoom");

    // Check if the rooms exist before adding items
    if (startRoom != nullptr) {
        startRoom->AddItem(key);
    } else {
        std::cout << "startRoom not found" << std::endl;
    }

    if (treasureRoom != nullptr) {
        treasureRoom->AddItem(sword);
    } else {
        std::cout << "treasureRoom not found" << std::endl;
    }

    // Create a Player
    Player player("Alice", 100);

    // Set the player's starting location
    player.SetLocation(gameWorld.GetRoom("startRoom"));

    // Game loop (basic interaction)
    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "Items in the room:" << std::endl;
        for (const Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
        }
        std::cout << "Options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Move to another room | ";
        std::cout << "4. Quit" << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            // Player looks around (no action required)
            std::cout << "You look around the room." << std::endl;
        } else if (choice == 2) {
            // Player interacts with an item in the room
            std::cout << "Enter the name of the item you want to interact with: ";
            std::string itemName;
            std::cin >> itemName;
            for (Item& item : player.GetLocation()->GetItems()) {
                if (item.GetName() == itemName) {
                    item.Interact();
                    break;
                }
            }
        } else if (choice == 3) {
            // Player moves to another room
            std::cout << "Enter the direction (e.g., north, south): ";
            std::string direction;
            std::cin >> direction;

            // Debugging: Print the direction input
            std::cout << "You chose direction: " << direction << std::endl;

            Room* nextRoom = player.GetLocation()->GetExit(direction);
            if (nextRoom != nullptr) {
                player.SetLocation(nextRoom);
                std::cout << "You move to the next room." << std::endl;
            } else {
                std::cout << "You can't go that way." << std::endl;
            }
        } else if (choice == 4) {
            // Quit the game
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}

#include <iostream>
#include <sstream>
#include "Area.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "CommandInterpreter.hpp"

std::string gameMapFilePath = "/Users/vedantpawar/CLionProjects/Coursework C++/game_map.txt"; // Update this path with your game map file path

int main() {
    std::cout << "Welcome to the Adventure Game!" << std::endl;
    std::cout << "Please select a difficulty level (easy, medium, difficult): ";
    std::string difficulty;
    std::cin >> difficulty;
    std::cin.ignore(); // Ignore newline character left in the input buffer

    // Create an Area
    Area gameWorld;

    // Load the game map from the file
    gameWorld.LoadMapFromFile(gameMapFilePath);

    // Create Items
    Item torch("torch", "A torch providing a flickering light.");
    Item sword("sword", "An ancient sword of great power.");
    Item treasure ("treasure", "A chest full of gold coins. YOU WIN!");

    // Create a Monster
    Monster boss("Dragon", 100);

    // Get the rooms
    auto startRoom = gameWorld.GetRoom("startRoom");
    auto bossRoom = gameWorld.GetRoom("bossRoom");
    auto hallwayRoom = gameWorld.GetRoom("hallway");
    auto treasureRoom = gameWorld.GetRoom("treasureRoom");

    // Add items to rooms
    if (startRoom != nullptr) {
        startRoom->AddItem(torch);
    }

    // Add the boss (monster) to bossRoom
    if (bossRoom != nullptr) {
        bossRoom->SetMonster(&boss);
    }

    // Add the sword to hallwayRoom
    if (hallwayRoom != nullptr) {
        hallwayRoom->AddItem(sword);
    }
    if (treasureRoom != nullptr) {
        treasureRoom->AddItem(treasure);
    }

    // Create a Player with the selected difficulty level
    Player player("Alice", difficulty);

    // Set the player's starting location
    player.SetLocation(startRoom);

    // Create a CommandInterpreter
    CommandInterpreter interpreter(&player, treasureRoom);

    // Game loop (basic interaction)
    while (true) {
        // If the player health = 0, game over
        if (player.GetHealth() <= 0) {
            std::cout << "You have been defeated by the " << boss.GetName() << "!" << std::endl;
            std::cout << "Game Over!" << std::endl;
            exit(0);
            break;
        }
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;

        // Display player's health
        std::cout << "Player Health: " << player.GetHealth() << std::endl;

        // Check if the room has a monster
        if (player.GetLocation()->HasMonster()) {
            const Monster* currentMonster = player.GetLocation()->GetMonster();
            std::cout << "A fearsome " << currentMonster->GetName() << " is in this room!" << std::endl;
            std::cout << "Monster Health: " << currentMonster->GetHealth() << std::endl;

            // Dragon attacks the player when in bossRoom
            if (player.GetLocation() == bossRoom) {
                std::cout << "The Dragon attacks you!" << std::endl;
                player.Hit(&boss);
            }
        }

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
        std::cout << " Look around | ";
        std::cout << " Pick item | ";
        std::cout << " Drop item | ";
        std::cout << " Move north/south/east/west | ";
        std::cout << " Hit  | ";
        std::cout << " Quit" << std::endl;

        std::string command;
        std::getline(std::cin, command);

        // Pass the command to the interpreter
        interpreter.interpretCommand(command);
    }

    return 0;
}

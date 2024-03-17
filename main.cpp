#include <iostream>
#include <sstream>
#include "Area.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "CommandInterpreter.hpp"

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

    // Add items to rooms
    if (startRoom != nullptr) {
        startRoom->AddItem(torch);
    }

    // Create a Player
    Player player("Alice", 100);

    // Set the player's starting location
    player.SetLocation(startRoom);

    // Create a CommandInterpreter
    CommandInterpreter interpreter(&player);

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
        std::cout << " Look around | ";
        std::cout << " Pick up an item | ";
        std::cout << " Drop an item | ";
        std::cout << " Move to another room | ";
        std::cout << " Quit" << std::endl;

        std::string command;
        std::getline(std::cin, command);

        // Pass the command to the interpreter
        interpreter.interpretCommand(command);
    }

    return 0;
}



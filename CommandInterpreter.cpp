#include "CommandInterpreter.hpp"
#include "Player.hpp" // Include the header for Player if needed

#include <iostream>
#include <sstream>
#include <vector> // Include any other necessary headers

CommandInterpreter::CommandInterpreter(Player* player) : player_(player) {}

void CommandInterpreter::interpretCommand(const std::string& command) {
    std::istringstream commandStream(command);
    std::string singleCommand;
    while (std::getline(commandStream, singleCommand, ';')) {
        interpretSingleCommand(singleCommand);
    }
}

void CommandInterpreter::interpretSingleCommand(const std::string& singleCommand) {
    std::istringstream iss(singleCommand);
    std::string action;
    iss >> action;

    if (action == "move") {
        std::string direction;
        iss >> direction;
        player_->move(direction);
    } else if (action == "pick") {
        std::string item;
        std::getline(iss >> std::ws, item); // Read the entire line after 'pick'
        player_->pickUpItem(item);
    } else if (action == "drop") {
        std::string item;
        std::getline(iss >> std::ws, item); // Read the entire line after 'drop'
        player_->dropItem(item);
    } else if (action == "inventory") {
        const std::vector<Item>& inventory = player_->GetInventory();
        std::cout << "Inventory:" << std::endl;
        for (const Item& item : inventory) {
            std::cout << "- " << item.GetName() << std::endl;
        }
    } else if (action == "look") {
        player_->lookAround();
    } else {
        std::cout << "Unknown command: " << singleCommand << std::endl;
    }
}

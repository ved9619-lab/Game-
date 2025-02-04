#include "CommandInterpreter.hpp"
#include "Player.hpp"

#include <iostream>
#include <sstream>
#include <vector>
//#include"SpecialAbility.hpp"

CommandInterpreter::CommandInterpreter(Player* player, Room* treasureRoom) : player_(player), treasureRoom_(treasureRoom) {}

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
        player_->move(direction, treasureRoom_);
    } else if (action == "pick") {
        std::string item;
        std::getline(iss >> std::ws, item);
        player_->pickUpItem(item);
    } else if (action == "drop") {
        std::string item;
        std::getline(iss >> std::ws, item);
        player_->dropItem(item);
    } else if (action == "inventory") {
        const std::vector<Item>& inventory = player_->GetInventory();
        std::cout << "Inventory:" << std::endl;
        for (const Item& item : inventory) {
            std::cout << "- " << item.GetName() << std::endl;
        }
    } else if (action == "look") {
        player_->lookAround();
    } else if (action == "quit") {
        std::cout << "Quitting game." << std::endl;
        exit(0);
    } else if (action == "hit") {
        if (player_->GetLocation()->HasMonster()) {
            Monster* currentMonster = player_->GetLocation()->GetMonster();
            std::cout << "Monster Health: " << currentMonster->GetHealth() << std::endl;
            player_->Hit(currentMonster);
        } else {
            std::cout << "There is no monster here to hit." << std::endl;
        }
    } else if (action == "special") {
        player_->SpecialAbility();
    } else {
        std::cout << "Unknown command: " << singleCommand << std::endl;
    }
}

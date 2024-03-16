#include "CommandInterpreter.hpp"
#include "Player.hpp"

CommandInterpreter::CommandInterpreter(Player* player) : player_(player) {}

void CommandInterpreter::interpretCommand(const std::string& command) {
    std::istringstream iss(command);
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
    } else if (action == "look") {
        player_->lookAround();
    } else {
        std::cout << "Unknown command: " << command << std::endl;
    }
}

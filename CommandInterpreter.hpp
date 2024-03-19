#ifndef COMMANDINTERPRETER_HPP
#define COMMANDINTERPRETER_HPP

#include <iostream>
#include <sstream>
#include "Player.hpp"
#include <string>
#include <vector>
#include "Room.hpp"

class Player; // Forward declaration

class CommandInterpreter {
public:
    CommandInterpreter(Player* player);
    void interpretCommand(const std::string& command);

private:
    Player* player_;
    void interpretSingleCommand(const std::string& singleCommand);
};

#endif // COMMANDINTERPRETER_HPP


#ifndef COMMANDINTERPRETER_HPP
#define COMMANDINTERPRETER_HPP

#include <iostream>
#include <sstream>
#include "Player.hpp"

#include <string>
class Player;

class CommandInterpreter {
public:
    CommandInterpreter(Player* player);
    void interpretCommand(const std::string& command);
private:
    Player* player_;
};


#endif // COMMANDINTERPRETER_HPP

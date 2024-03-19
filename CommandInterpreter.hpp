#ifndef COMMANDINTERPRETER_HPP
#define COMMANDINTERPRETER_HPP

#include "Player.hpp"
#include "Room.hpp"

class CommandInterpreter {
private:
    Player* player_;
    Room* treasureRoom_;

public:
    CommandInterpreter(Player* player, Room* treasureRoom);
    void interpretCommand(const std::string& command);
    void interpretSingleCommand(const std::string& singleCommand);
};

#endif

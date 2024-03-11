//
// Created by Vedant Pawar on 11/03/2024.
//

#ifndef COURSEWORK_C___PLAYER_HPP
#define COURSEWORK_C___PLAYER_HPP

#include "Character.hpp"

class Room;  // Forward declaration of Room class

class Player : public Character {
private:
    Room* location;

public:
    Player(const std::string& name, int health);
    Room* GetLocation();
    void SetLocation(Room* room);
};


#endif //COURSEWORK_C___PLAYER_HPP

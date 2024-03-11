//
// Created by Vedant Pawar on 11/03/2024.
//

#include "Player.hpp"
#include "Room.hpp"  // Include the actual definition of Room class

Player::Player(const std::string& name, int health) : Character(name, health), location(nullptr) {}

Room* Player::GetLocation() {
    return location;
}

void Player::SetLocation(Room* room) {
    location = room;
}


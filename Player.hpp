#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Room.hpp"
#include "Monster.hpp"
#include "Item.hpp"

#include <string>
#include <vector>

class Player {
public:
    Player(const std::string& name, int health);

    void move(const std::string& direction);
    void pickUpItem(const std::string& itemName);
    void dropItem(const std::string& itemName);
    const std::vector<Item>& GetInventory() const;
    void lookAround() const;
    void Hit(Monster* monster);

    Room* GetLocation() const; // Function declaration for GetLocation
    void SetLocation(Room* room); // Function declaration for SetLocation
    int GetHealth() const; // Function declaration for GetHealth

private:
    std::string name;
    int health;
    Room* location;
    std::vector<Item> inventory;

    int RollDice() const; // Helper function for damage calculation
};

#endif  // PLAYER_HPP

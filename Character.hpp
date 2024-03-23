//
// Created by Vedant Pawar on 11/03/2024.
//

#ifndef COURSEWORK_C___CHARACTER_HPP
#define COURSEWORK_C___CHARACTER_HPP


#include <string>
#include <vector>
#include "Item.hpp"  // Include the Item class

class Character {
protected:
    std::string name;
    int health;
    std::vector<Item> inventory;

public:
    Character(const std::string& name, int health);
    void TakeDamage(int damage);
    void PickUpItem(Item& item);
};



#endif //COURSEWORK_C___CHARACTER_HPP



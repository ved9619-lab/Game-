//
// Created by Vedant Pawar on 11/03/2024.
//

#include <iostream>
#include "Character.hpp"
#include "Item.hpp"  // Include the actual definition of Item class

Character::Character(const std::string& name, int health) : name(name), health(health) {}

void Character::TakeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Character::PickUpItem(Item& item) {
    inventory.push_back(item);
    std::cout << name << " picked up " << item.GetName() << "." << std::endl;
}


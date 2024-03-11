//
// Created by Vedant Pawar on 11/03/2024.
//

#include <iostream>
#include "Item.hpp"

Item::Item(const std::string& name, const std::string& desc) : name(name), description(desc) {}

const std::string& Item::GetName() const {
    return name;
}

const std::string& Item::GetDescription() const {
    return description;
}

void Item::Interact() {
    std::cout << "You interact with " << name << ". " << description << std::endl;
}
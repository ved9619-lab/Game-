#include <iostream>
#include "Item.hpp"

Item::Item(const std::string& name, const std::string& desc) : name(name), description(desc) {}

const std::string& Item::GetName() const {
    return name;
}

const std::string& Item::GetDescription() const {
    return description;
}

// Define Interact as const
void Item::Interact() const {
    std::cout << "You interact with " << name << ". " << description << std::endl;
}


//
// Created by Vedant Pawar on 11/03/2024.
//

#ifndef COURSEWORK_C___ITEM_HPP
#define COURSEWORK_C___ITEM_HPP


#include <string>

class Item {
private:
    std::string name;
    std::string description;

public:
    Item(const std::string& name, const std::string& desc);
    const std::string& GetName() const;
    const std::string& GetDescription() const;
    void Interact();
};


#endif //COURSEWORK_C___ITEM_HPP

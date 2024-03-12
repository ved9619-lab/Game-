#ifndef COURSEWORK_C___AREA_HPP
#define COURSEWORK_C___AREA_HPP

#include <string>
#include <map>
#include "Room.hpp"

class Area {
private:
    std::map<std::string, Room*> rooms;

public:
    // Add a function to get rooms
    const std::map<std::string, Room*>& GetRooms() const;

    void AddRoom(const std::string& name, Room* room);
    Room* GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction);
    void LoadMapFromFile(const std::string& filename);
};

#endif //COURSEWORK_C___AREA_HPP


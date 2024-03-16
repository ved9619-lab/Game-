#include "Area.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

const std::map<std::string, Room*>& Area::GetRooms() const {
    return rooms;
}

void Area::AddRoom(const std::string& name, Room* room) {
    rooms[name] = room;
}

Room* Area::GetRoom(const std::string& name) {
    if (rooms.count(name) > 0) {
        return rooms[name];
    } else {
        return nullptr;
    }
}

void Area::ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction) {
    Room* room1 = GetRoom(room1Name);
    Room* room2 = GetRoom(room2Name);
    if (room1 != nullptr && room2 != nullptr) {
        room1->AddExit(direction, room2);
    }
}

void Area::LoadMapFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string roomName, desc;
        std::getline(iss, roomName, '|');

        if (rooms.count(roomName) == 0) {  // New room
            std::getline(iss, desc, '|');
            rooms[roomName] = new Room(desc);
        } else {  // Existing room
            std::string direction, room2Name;
            std::getline(iss, room2Name, '|');
            std::getline(iss, direction, '|');
            rooms[roomName]->AddExit(direction, rooms[room2Name]);
        }
    }
}

//
// Created by maxhe on 11/29/2025.
//

#ifndef DUNGEONLAYOUT__H
#define DUNGEONLAYOUT__H
#include "../world/Room.h"
#include <map>


class DungeonLayout {
    private:
    std::map<RoomID, Room> rooms;

    public:
    void loadRooms();
    void addRoom(const RoomID& id, const Room& room);
    Room& getRoom(const RoomID& id);
    bool hasRoom(const RoomID& id) const;


};

#endif //DUNGEONLAYOUT__H

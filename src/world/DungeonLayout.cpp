//
// Created by maxhe on 11/29/2025.
//
#include "../../include/world/DungeonLayout.h"

 void DungeonLayout::loadRooms(){ // not used


 }

 void DungeonLayout::addRoom(const RoomID& id, const Room& room){
    rooms.emplace(id, room);

 }
 
 Room& DungeonLayout::getRoom(const RoomID& id){
    return rooms.at(id);

 }

 bool DungeonLayout::hasRoom(const RoomID& id) const{
     return rooms.find(id) != rooms.end();

 }



    
    
    
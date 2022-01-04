#include <iostream>
#include <cstring>
#include "Room.h"
#include <map>
using namespace std;

Room::Room(){
    
}

Room::~Room(){
    
}

void Room::setItems(vector<Item*>ItemVect) {
    m_itemVector = ItemVect;
}

void Room::setExits(map<char, int> ExMap) {
    m_exMap = ExMap;
}

void Room::setNumber(int roomNum){
    m_roomNumber = roomNum;
}

void Room::setName(char name[]){
    m_roomName = name;
}


void Room::setDesc(char desc[]){
    strcpy(desc,  m_roomDescription); 
}
    
vector<Item*> Room::getItems(){
    return m_itemVector;
}
    
map<char, int> Room::getExits(){
    return m_exMap;
}
    
int Room::getExitRoomNumber(char exitName){
    return 0;
}
    
/*Item* Room::pickupItem(){
    return null;
}

void Room::dropItem(Item*){
    
}*/

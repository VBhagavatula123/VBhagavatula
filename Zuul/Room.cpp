#include <iostream>
#include <cstring>
#include "Room.h"
#include <map>
using namespace std;

Room::Room(int roomNum){
    m_roomNumber = roomNum;
}

Room::~Room(){
    
}

void Room::setItems(vector<Item*>ItemVect) {
    m_itemVector = ItemVect;
}

void Room::setExits(map<char, int> ExMap) {
    m_exMap = ExMap;
}


void Room::setName(char* name){
    m_roomName = new char[10];
    strcpy(m_roomName, name);
}

void Room::setDesc(char* desc){
    m_roomDescription = new char[80];
    strcpy(m_roomDescription, desc);
}

char* Room::getName(){
    return m_roomName;
}

char* Room::getDesc(){
    return m_roomDescription;
}
  
vector<Item*> Room::getItems(){
    return m_itemVector;
}
    
map<char, int> Room::getExits(){
    return m_exMap;
}
    
int Room::getExitRoomNumber(char exitLetter){
    return m_exMap[exitLetter];
}
    

void Room::addItem(char* itemname, char* itemcolor){
    Item* newItem = new Item();
    newItem->name = itemname;
    newItem->color = itemcolor;
    m_itemVector.push_back(newItem);
}

void Room::pickupItem(char* itemname, vector<Item*> &PlayerInventoryVectPtr) {
    for(int i = 0; i<m_itemVector.size(); i++){
        if(strcmp(m_itemVector[i]->name, itemname) == 0){
            Item* newItem = new Item();
            newItem->name = m_itemVector[i]->name;
            newItem->color = m_itemVector[i]->color;
            PlayerInventoryVectPtr.push_back(newItem);
            //delete the data
            delete m_itemVector[i];
            //Remove the item from vector
            m_itemVector.erase(m_itemVector.begin()+i);
        }
    }
}

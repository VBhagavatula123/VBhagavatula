
/*

This is the header file for the room class. in the file, we declare the members of the class. The public members are needed for 
main.cpp where as the private ones are needed only for the functions in Room.cpp

*/

#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

struct Item {
	char* name;
	char* color;
};

class Room {
  public:
    Room(int roomNum);
    ~Room();
    
    void setItems(vector<Item*> itemVect);
    void setExits(map<char, int> ExMap);
    
    void setName(char* name);
    void setDesc(char* desc);
    
    char* getName();
    char* getDesc();
    vector<Item*> getItems();
    map<char, int> getExits();
    
    int getExitRoomNumber(char exitName);
    
    void pickupItem(char* itemname, char* itemcolor, vector<Item*> &PlayerInventoryVectPtr);
    void addItem(char* itemname, char* itemcolor);
  
  private:
    int m_roomNumber;
    char* m_roomName;
    char* m_roomDescription;
    vector<Item*> m_itemVector;
    map<char, int> m_exMap;
};

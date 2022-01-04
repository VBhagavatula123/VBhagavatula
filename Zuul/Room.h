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
    Room();
    ~Room();
    
    void setItems(vector<Item*> itemVect);
    void setExits(map<char, int> ExMap);
    
    void setNumber(int roomNumber);
    void setName(char* name);
    void setDesc(char* desc);
    
    vector<Item*> getItems();
    map<char, int> getExits();
    
    int getExitRoomNumber(char exitName);
    
    /*Item* pickupItem();
    void dropItem(Item*);*/
    
  
  protected:
    int m_roomNumber;
    char* m_roomName;
    char* m_roomDescription;
    vector<Item*> m_itemVector;
    map<char, int> m_exMap;
};

#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"
#include std::map<Key, T> ;

using namespace std;

struct Item{
	char name[];
	char color[];
}

};

int main()
{
vector<Room*> RoomVectPtr;
vector<Item*> PlayerInventoryVectPtr;


cout << "you are currently in the 1-20 lab at sunset, you have 3 possible exits, N, S and E" << endl;
 Room* room1 = new Room();
        room1->setName("Room1");
        room1->setDesc("You are in Room1");
        vector<Item*> Room1ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room1ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room1ItemsVect.push_back(newItem);
        
        room1->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap1;
        exitmap1['E'] = 2;
        exitmap1['S'] = 6;
        room1->setExits(exitmap);
        
        RoomVectPtr.push_back(room1);
 RoomVectPtr(1) = new Room();
 RoomVectPtr() = new Room();
 RoomVectPtr4 = new Room();
 RoomVectPtr5 = new Room();
 RoomVectPtr6 = new Room();
 RoomVectPtr7 = new Room();
 RoomVectPtr3 = new Room();
 RoomVectPtr8 = new Room();
 RoomVectPtr9 = new Room();
 RoomVectPtr10 = new Room();
 RoomVectPtr12 = new Room();
 RoomVectPtr13 = new Room();
 RoomVectPtr14 = new Room();
 RoomVectPtr15 = new Room();
 
 
 
 
 
 
 
 
 
 
 
 
 
 /*if(roomNumber == 1) {
    cout << "You have entered the Bathroom" << endl;
    cout << "Exits: WEST"
  }
  if(roomNumber == 2) {
    cout << "You have entered the Bedroom" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 3) {
    cout << "You have entered the Walking Closet" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 4) {
    cout << "You have entered the Dining Area" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 5) {
    cout << "You have entered the Kitchen" << endl;
    cout << "Exits: NORTH"
  }
  if(roomNumber == 6) {
    cout << "You have entered the Bonus Room" << endl;
    cout << "Exits: EAST"
  }
  if(roomNumber == 7) {
    cout << "You have entered the Gaming Room" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 8) {
    cout << "You have entered the Master Bedroom" << endl;
    cout << "Exits: NORTH"
  }
  if(roomNumber == 9) {
    cout << "You have entered the Kids Room" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 10) {
    cout << "You have entered the Garage" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 11) {
    cout << "You have entered the Front Yard" << endl;
    cout << "Exits: WEST"
  }
  if(roomNumber == 12) {
    cout << "You have entered the Back Yard" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 13) {
    cout << "You have entered the Theater Room" << endl;
    cout << "Exits: SOUTH"
  }
  if(roomNumber == 14) {
    cout << "You have entered the Accolades Room" << endl;
    cout << "Exits: EAST"
  }
  if(roomNumber == 15) {
    cout << "You have entered the Snacks Closet" << endl;
    cout << "Exits: SOUTH"
  }*/


}

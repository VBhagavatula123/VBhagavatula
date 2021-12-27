#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"


using namespace std;

struct items{
  char Weapon[10];
    int money;
    int roomAge;
    char name[10];
    int song;
};

int main()
{
vector<Room*> RoomVectPtr;
 
 
 Room* nextRoom = new Room();
 
 
 if(roomNumber == 1) {
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
  }


}

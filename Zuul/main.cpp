#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"
#include <map>

using namespace std;

int main()
{
    vector<Room*> RoomVectPtr;
    vector<Item*> PlayerInventoryVectPtr;

    Room* room1 = new Room();
        room1->setNumber(1);
        
        char txt[50] = "Room1";
        room1->setName(txt);
        
        strcpy(txt,"You are in Room1");
        room1->setDesc(txt);
        
        vector<Item*> Room1ItemsVect;
        Item* newItem = new Item();
        strcpy(txt, "candy");
        newItem->name = txt;
        strcpy(txt, "silver");
        newItem->color = txt;
         //Add the newItem struct pointer to our student vector, studVect
        Room1ItemsVect.push_back(newItem);
        
        newItem = new Item();
        strcpy(txt, "mop");
        newItem->name = txt;
        strcpy(txt, "gold");
        newItem->color = txt;
         //Add the newItem struct pointer to our student vector, studVect
        Room1ItemsVect.push_back(newItem);
        
        room1->setItems(Room1ItemsVect);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap1;
        exitmap1['E'] = 2;
        exitmap1['S'] = 6;
        
        
        
        room1->setExits(exitmap1);
        
        RoomVectPtr.push_back(room1);
        
    Room* room2 = new Room();
        room2->setNumber(2);
        strcpy(txt, "Room2");
        room2->setName(txt);
        strcpy(txt, "You are in Room2");
        room2->setDesc(txt);
        vector<Item*> Room2ItemsVect;
        newItem = new Item();
        strcpy(txt, "candy");
        newItem->name = txt;
        strcpy(txt, "blue");
        newItem->color = txt;
         //Add the newItem struct pointer to our student vector, studVect
        Room2ItemsVect.push_back(newItem);
        newItem = new Item();
        strcpy(txt, "mop");
        newItem->name = txt;
        strcpy(txt, "black");
        newItem->color = txt;
         //Add the newItem struct pointer to our student vector, studVect
        Room2ItemsVect.push_back(newItem);
        
        room2->setItems(Room2ItemsVect);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap2;
        exitmap2['W'] = 1;
        exitmap2['E'] = 3;
        exitmap2['S'] = 7;
        room2->setExits(exitmap2);
        
        RoomVectPtr.push_back(room2);
        
    Room* room3 = new Room();
        room3->setNumber(3);
        strcpy(txt, "Room3");
        room2->setName(txt);
        strcpy(txt, "You are in Room2");
        room3->setDesc(txt);
        vector<Item*> Room3ItemsVect;
        newItem = new Item();
        strcpy(txt, "candy");
        newItem->name = txt;
        strcpy(txt, "silver");
        newItem->color = txt;
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        Room3ItemsVect.push_back(newItem);
        newItem = new Item();
        strcpy(txt, "mop");
        newItem->name = txt;
        strcpy(txt, "gold");
        newItem->color = txt;
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        Room3ItemsVect.push_back(newItem);
        
        room3->setItems(Room3ItemsVect);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap3;
        exitmap3['W'] = 2;
        exitmap3['E'] = 4;
        exitmap3['S'] = 8;
        room3->setExits(exitmap3);
        
        RoomVectPtr.push_back(room3); 
 
    /*Room* room4 = new Room();
        room4->setName("Room4");
        room4->setDesc("You are in Room4");
        vector<Item*> Room4ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room4ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room4ItemsVect.push_back(newItem);
        
        room4->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap4;
        exitmap4['W'] = 3;
        exitmap4['E'] = 5;
        exitmap4['S'] = 9;
        room4->setExits(exitmap);
        
        RoomVectPtr.push_back(room4);
        
    Room* room5 = new Room();
        room5->setName("Room5");
        room5->setDesc("You are in Room5");
        vector<Item*> Room5ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room5ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room5ItemsVect.push_back(newItem);
        
        room5->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap5;
        exitmap5['W'] = 4;
        exitmap5['S'] = 10;
        room5->setExits(exitmap);
        
        RoomVectPtr.push_back(room5);
 
    Room* room6 = new Room();
        room6->setName("Room6");
        room6->setDesc("You are in Room6");
        vector<Item*> Room6ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room6ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room6ItemsVect.push_back(newItem);
        
        room6->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitma6;
        exitmap6['N'] = 1;
        exitmap6['E'] = 7;
        exitmap6['S'] = 11;
        room6->setExits(exitmap);
        
        RoomVectPtr.push_back(room6); 
 
    Room* room7 = new Room();
        room7->setName("Room7");
        room7->setDesc("You are in Room7");
        vector<Item*> Room7ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room7ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room7ItemsVect.push_back(newItem);
        
        room7->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap7;
        exitmap7['N'] = 2;
        exitmap7['W'] = 6;
        exitmap7['E'] = 8;
        exitmap7['S'] = 12;
        room7->setExits(exitmap7);
        
        RoomVectPtr.push_back(room7); 
 
    Room* room8 = new Room();
        room8->setName("Room8");
        room8->setDesc("You are in Room8");
        vector<Item*> Room8ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room8ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room8ItemsVect.push_back(newItem);
        
        room8->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap8;
        exitmap8['N'] = 3;
        exitmap8['W'] = 7;
        exitmap8['E'] = 9;
        exitmap8['S'] = 13;
        room8->setExits(exitmap8);
        
        RoomVectPtr.push_back(room8);
        
    Room* room9 = new Room();
        room9->setName("Room9");
        room9->setDesc("You are in Room9");
        vector<Item*> Room9ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room9ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room9ItemsVect.push_back(newItem);
        
        room9->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap9;
        exitmap9['N'] = 4
        exitmap9['W'] = 8
        exitmap9['E'] = 10;
        exitmap9['S'] = 14;
        room9->setExits(exitmap9);
        
        RoomVectPtr.push_back(room9);
        
    Room* room10 = new Room();
        room10->setName("Room10");
        room10->setDesc("You are in Room10");
        vector<Item*> Room10ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room10ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room10ItemsVect.push_back(newItem);
        
        room10->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap10;
        exitmap10['N'] = 5;
        exitmap10['W'] = 9;
        exitmap10['S'] = 15;
        room10->setExits(exitmap10);
        
        RoomVectPtr.push_back(room10);
        
    Room* room11 = new Room();
        room11->setName("Room11");
        room11->setDesc("You are in Room11");
        vector<Item*> Room11ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room11ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room11ItemsVect.push_back(newItem);
        
        room11->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap11;
        exitmap11['E'] = 12;
        exitmap11['N'] = 6;
        room11->setExits(exitmap11);
        
        RoomVectPtr.push_back(room11);
        
    Room* room12 = new Room();
        room12->setName("Room12");
        room12->setDesc("You are in Room12");
        vector<Item*> Room12ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room12ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room12ItemsVect.push_back(newItem);
        
        room12->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap12;
        exitmap12['N'] = 7;
        exitmap12['E'] = 13;
        exitmap12['W'] = 11;
        room12->setExits(exitmap12);
        
        RoomVectPtr.push_back(room12);
        
    Room* Room13 = new Room();
        room13->setName("Room13");
        room13->setDesc("You are in Room13");
        vector<Item*> Room13ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room13ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room13ItemsVect.push_back(newItem);
        
        room13->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap13;
        exitmap13['W'] = 12;
        exitmap13['E'] = 14;
        exitmap13['N'] = 8;
        room13->setExits(exitmap13);
        
        RoomVectPtr.push_back(room13);
        
    Room* room14 = new Room();
        room14->setName("Room14");
        room14->setDesc("You are in Room14");
        vector<Item*> Room14ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room14ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room14ItemsVect.push_back(newItem);
        
        room14->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap14;
        exitmap14['E'] = 15;
        exitmap14['N'] = 9;
        exitmap14['W'] = 13;
        room14->setExits(exitmap14);
        
        RoomVectPtr.push_back(room14);
        
    Room* room15 = new Room();
        room15->setName("Room15");
        room15->setDesc("You are in Room15");
        vector<Item*> Room15ItemsVect;
        items* newItem = new Item();
        newItem->name = "candy";
        newItem->color = "silver"
         //Add the newItem struct pointer to our student vector, studVect
        Room15ItemsVect.push_back(newItem);
        items* newItem = new Item();
        newItem->name = "mop";
        newItem->color = "gold"
         //Add the newItem struct pointer to our student vector, studVect
        Room15ItemsVect.push_back(newItem);
        
        room15->setItems();
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap15;
        exitmap15['W'] = 14;
        exitmap15['N'] = 10;
        room15->setExits(exitmap15);
        
        RoomVectPtr.push_back(room15);
     */   
    
    int roomNumber = 1;
    Room* currentRoom = RoomVectPtr[roomNumber-1];
    map<char, int> exitmap = currentRoom->getExits();
    
    cout << "you are currently in Room1 of ESCAPE ROOMS, you have 2 possible exits, S and E" << endl;
   
    map<char, int>::iterator it = exitmap1.begin();
        
        while (it != exitmap1.end())
    {
        // Accessing KEY from element pointed by it.
        char letter = it->first;
        // Accessing VALUE from element pointed by it.
        int number = it->second;
        cout << letter << " :: " << number << endl;
        // Increment the Iterator to point to next entry
        it++;
    }
    while(true)
    {
        
        
    }
 
 
 
 
 
 
 
 
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

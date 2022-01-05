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
    char roomname[10];
    char roomdesc[80];
   // char itemname[10];
    //char itemcolor[10];
    
    char* book = (char*)"book";
    char* candy = (char*)"candy";
    char* mop = (char*)"mop";
    char* cup = (char*)"cup";
    char* ring = (char*)"ring";
    
    char* gold = (char*)"gold";
    char* silver = (char*)"silver";
    char* bronze = (char*)"bronze";
    
    Room* room1 = new Room(1);
        strcpy(roomname, "Room1");
        room1->setName(roomname);
        
        strcpy(roomdesc, "You are in Room1");
        room1->setDesc(roomdesc);

         //Add the newItem struct pointer to our item vector inside room
        room1->addItem(candy, silver);
         //Add the newItem struct pointer to our student vector, studVect;
        room1->addItem(book, gold);

        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap1;
        exitmap1['E'] = 2;
        exitmap1['S'] = 6;
        room1->setExits(exitmap1);
        
        RoomVectPtr.push_back(room1);
        
    Room* room2 = new Room(2);
        strcpy(roomname, "Room2");
        room2->setName(roomname);
        strcpy(roomdesc, "You are in Room2");
        room2->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our student vector, studVect
         //Add the newItem struct pointer to our student vector, studVect
        room2->addItem(mop, silver);
        
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap2;
        exitmap2['W'] = 1;
        exitmap2['E'] = 3;
        exitmap2['S'] = 7;
        room2->setExits(exitmap2);
        
        RoomVectPtr.push_back(room2);
        
    Room* room3 = new Room(3);
        strcpy(roomname, "Room3");
        room3->setName(roomname);
        strcpy(roomdesc, "You are in Room3");
        room3->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room3->addItem(book, silver);
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap3;
        exitmap3['W'] = 2;
        exitmap3['E'] = 4;
        exitmap3['S'] = 8;
        room3->setExits(exitmap3);
        
        RoomVectPtr.push_back(room3);
 
    Room* room4 = new Room(4);
        strcpy(roomname, "Room4");
        room4->setName(roomname);
        strcpy(roomdesc, "You are in Room4");
        room4->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room4->addItem(mop, silver);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap4;
        exitmap4['W'] = 3;
        exitmap4['E'] = 5;
        exitmap4['S'] = 9;
        room4->setExits(exitmap4);
        
        RoomVectPtr.push_back(room4);
        
    Room* room5 = new Room(5);
        strcpy(roomname, "Room5");
        room5->setName(roomname);
        strcpy(roomdesc, "You are in Room5");
        room5->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room5->addItem(mop, bronze);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap5;
        exitmap5['W'] = 4;
        exitmap5['S'] = 10;
        room5->setExits(exitmap5);
        
        RoomVectPtr.push_back(room5);
 
    Room* room6 = new Room(6);
        strcpy(roomname, "Room6");
        room6->setName(roomname);
        strcpy(roomdesc, "You are in Room6");
        room6->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room6->addItem(candy, bronze);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap6;
        exitmap6['N'] = 1;
        exitmap6['E'] = 7;
        exitmap6['S'] = 11;
        room6->setExits(exitmap6);
        
        RoomVectPtr.push_back(room6); 
 
   Room* room7 = new Room(7);
        strcpy(roomname, "Room7");
        room7->setName(roomname);
        strcpy(roomdesc, "You are in Room7");
        room7->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room7->addItem(cup, gold);
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap7;
        exitmap7['N'] = 2;
        exitmap7['W'] = 6;
        exitmap7['E'] = 8;
        exitmap7['S'] = 12;
        room7->setExits(exitmap7);
        
        RoomVectPtr.push_back(room7); 
 
    Room* room8 = new Room(8);
        strcpy(roomname, "Room8");
        room8->setName(roomname);
        strcpy(roomdesc, "You are in Room8");
        room8->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room8->addItem(ring, gold);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap8;
        exitmap8['N'] = 3;
        exitmap8['W'] = 7;
        exitmap8['E'] = 9;
        exitmap8['S'] = 13;
        room8->setExits(exitmap8);
        
        RoomVectPtr.push_back(room8);
        
    Room* room9 = new Room(9);
        strcpy(roomname, "Room9");
        room9->setName(roomname);
        strcpy(roomdesc, "You are in Room9");
        room9->setDesc(roomdesc);
        
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room9->addItem(cup, bronze);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap9;
        exitmap9['N'] = 4;
        exitmap9['W'] = 8;
        exitmap9['E'] = 10;
        exitmap9['S'] = 14;
        room9->setExits(exitmap9);
        
        RoomVectPtr.push_back(room9);
        
    Room* room10 = new Room(10);
        strcpy(roomname, "Room10");
        room10->setName(roomname);
        strcpy(roomdesc, "You are in Room10");
        room10->setDesc(roomdesc);
         //Add the newItem struct pointer to our item vector, Room3ItemsVect
        room10->addItem(mop, gold);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap10;
        exitmap10['N'] = 5;
        exitmap10['W'] = 9;
        exitmap10['S'] = 15;
        room10->setExits(exitmap10);
        
        RoomVectPtr.push_back(room10);
        
    Room* room11 = new Room(11);
        strcpy(roomname, "Room11");
        room11->setName(roomname);
        strcpy(roomdesc, "You are in Room11");
        room11->setDesc(roomdesc);
        
        room11->addItem(book, gold);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap11;
        exitmap11['E'] = 12;
        exitmap11['N'] = 6;
        room11->setExits(exitmap11);
        
        RoomVectPtr.push_back(room11);
        
    Room* room12 = new Room(12);
        strcpy(roomname, "Room12");
        room12->setName(roomname);
        strcpy(roomdesc, "You are in Room12");
        room12->setDesc(roomdesc);
        
        room12->addItem(ring, silver);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap12;
        exitmap12['N'] = 7;
        exitmap12['E'] = 13;
        exitmap12['W'] = 11;
        room12->setExits(exitmap12);
        
        RoomVectPtr.push_back(room12);
    
    Room* room13 = new Room(13);
        strcpy(roomname, "Room13");
        room13->setName(roomname);
        strcpy(roomdesc, "You are in Room13");
        room13->setDesc(roomdesc);
        
        room13->addItem(cup, silver);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap13;
        exitmap13['W'] = 12;
        exitmap13['E'] = 14;
        exitmap13['N'] = 8;
        room13->setExits(exitmap13);
        
        RoomVectPtr.push_back(room13);
        
     Room* room14 = new Room(14);
        strcpy(roomname, "Room14");
        room14->setName(roomname);
        strcpy(roomdesc, "You are in Room13");
        room14->setDesc(roomdesc);
        
        room14->addItem(book, bronze);

        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap14;
        exitmap14['E'] = 15;
        exitmap14['N'] = 9;
        exitmap14['W'] = 13;
        room14->setExits(exitmap14);
        
        RoomVectPtr.push_back(room14);
        
    Room* room15 = new Room(15);
        strcpy(roomname, "Room15");
        room15->setName(roomname);
        strcpy(roomdesc, "You are in Room15");
        room15->setDesc(roomdesc);
        
        room15->addItem(candy, gold);
        //Set the exits for room 1 in - 
        //Eg: Room1 has East and South exits. Add them to a hashmap and pass to setExits method 
        map<char, int> exitmap15;
        exitmap15['W'] = 14;
        exitmap15['N'] = 10;
        room15->setExits(exitmap15);
        
        RoomVectPtr.push_back(room15);
       
    
    //Start prompting the user to play
    char inputstr[7];
    int curRoomNum = 1;
    while(true){
        //Prompt for input from user, PLAY or QUIT
        cout << "What would you like to do?, Play or Quit ?" << endl;
        cin >> inputstr;
      
        //If player types quit, break out of the loop
        if (strcmp(inputstr, "Quit") == 0)
            break;
        else if(strcmp(inputstr, "Play") == 0)
        {
            while(true){
                char inputPickupItemName[10];
                char inputDropItemName[10];
                char inputDropItemColor[10];
                char inputExit;
                
                cout << endl;
                cout << "Welcome to Escape Room" << curRoomNum << endl;
                Room* currentRoom = RoomVectPtr[curRoomNum-1];
                
                cout << endl;
                cout << "Here are the items in your inventory currently.." << endl;
                //Check player's inventory.
                //If the player has two gold items and zero bronze items, player wins. 
                //End the game. Otherwise continue.
                for(int i =0; i < PlayerInventoryVectPtr.size(); i++) {
                    cout << PlayerInventoryVectPtr[i]->name << " - " << PlayerInventoryVectPtr[i]->color << endl;
                }
                
                cout << endl;
                cout << currentRoom->getDesc() << endl;
                cout << "The Following items are in this room: " << endl;
                
                vector<Item*> itemVect = currentRoom->getItems();
                for(int i =0; i < itemVect.size(); i++) {
                    cout << itemVect[i]->name << " - " << itemVect[i]->color << endl;
                }
                cout << endl;
                cout << "You win if you have at least 2 gold items and zero bronze items" << endl;
                cout << "If you want to pickup any item, please type item name" << endl;
                cin >> inputPickupItemName;
                currentRoom->pickupItem(inputPickupItemName, PlayerInventoryVectPtr);
                cout << endl;
                
                if(PlayerInventoryVectPtr.size() > 0) {
                    cout << endl;
                    cout << "If you want to drop items please type item name and color. Otherwise, type No" << endl;
                    cin >> inputDropItemName;
                    if(strcmp(inputDropItemName, "No") != 0){
                        cin >> inputDropItemColor;
                        currentRoom->addItem(inputDropItemName, inputDropItemColor);
                        for(int i = 0; i<PlayerInventoryVectPtr.size(); i++){
                            if(strcmp(PlayerInventoryVectPtr[i]->name, inputDropItemName) == 0){
                                //delete the data
                                delete PlayerInventoryVectPtr[i];
                                //Remove the item from vector
                                PlayerInventoryVectPtr.erase(PlayerInventoryVectPtr.begin()+i);
                            }
                        }
                    }
                }
                
                cout << endl;
                cout << "Here are the items in your inventory currently.." << endl;
                //Check player's inventory.
                //If the player has two gold items and zero bronze items, player wins. 
                //End the game. Otherwise continue.
                int goldCounter = 0;
                int bronzeCounter = 0;
                for(int i =0; i < PlayerInventoryVectPtr.size(); i++) {
                    cout << PlayerInventoryVectPtr[i]->name << " - " << PlayerInventoryVectPtr[i]->color << endl;
                    if(strcmp(PlayerInventoryVectPtr[i]->color, "gold") == 0)
                        goldCounter++;
                    if(strcmp(PlayerInventoryVectPtr[i]->color, "bronze") == 0)
                        bronzeCounter++;
                }
                
                if(goldCounter == 2 && bronzeCounter == 0 )
                {
                    cout << endl;
                    cout << "You have won the Game!!!" << endl;
                    break;
                }
                
                cout << endl;
                cout << "This room has the following exits leading to other rooms: " << endl;
                map<char, int> xmap = currentRoom->getExits();
                map<char, int>::iterator it = xmap.begin();
                while (it != xmap.end())
                {
                    // Accessing KEY from element pointed by it.
                    char letter = it->first;
                    // Accessing VALUE from element pointed by it.
                    int number = it->second;
                    cout << letter << " :: Room " << number << endl;
                    // Increment the Iterator to point to next entry
                    it++;
                }
                cout << endl;
                
                cout << "Type an exit letter and you will go to corresponding room" << endl;
                cin >> inputExit;
                
                curRoomNum = currentRoom->getExitRoomNumber(inputExit);
                
            }
            
              
        }
    }
}

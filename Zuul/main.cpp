#include <iostream>
#include <vector>
#include <cstring>
#include "Room.h"
#include <map>

using namespace std;

//void AddItem(vector<Item*> &itemVect, char* name, char* color);

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
        room2->addItem(candy, gold);
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
        room3->addItem(mop, gold);
        
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
    
    /*for(int i =0; i < RoomVectPtr.size(); i++) {
        Room* currentRoom = RoomVectPtr[i];
        
        cout << "You are currently in Room " << i+1 << " of TreasureHunt Games, there are exits leading to other rooms: " << endl;
        cout << endl;
        cout << "Room name: " << currentRoom->getName() << endl;
        cout << "Room desc: " << currentRoom->getDesc() << endl << endl;
        cout << "Following items are found in this room: " << endl;
        
        vector<Item*> itemVect = currentRoom->getItems();
        for(int i =0; i < itemVect.size(); i++) {
            cout << itemVect[i]->color << "::" << itemVect[i]->name << endl;
        }
        cout << endl;
        cout << "This room has the following exits leading to other rooms: " << endl;
        map<char, int> exitmap = currentRoom->getExits();
        map<char, int>::iterator it = exitmap.begin();
        while (it != exitmap.end())
        {
            // Accessing KEY from element pointed by it.
            char letter = it->first;
            // Accessing VALUE from element pointed by it.
            int number = it->second;
            cout << letter << " :: " << number << endl;
            // Increment the Iterator to point to next entry
            it++;
        }
        cout << endl;
    }*/
    
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
                
                cout << "Alright!! Welcome to Escape Room" << curRoomNum << endl;
                Room* currentRoom = RoomVectPtr[curRoomNum-1];
                
                cout << currentRoom->getDesc() << endl;
                cout << "Following items are in this room: " << endl;
                
                vector<Item*> itemVect = currentRoom->getItems();
                for(int i =0; i < itemVect.size(); i++) {
                    cout << itemVect[i]->name << " - " << itemVect[i]->color << endl;
                }
                cout << "You win if you have at least 2 gold items and zero bronze items" << endl;
                cout << "If you like to pickup any item, please type item name" << endl;
                cin >> inputPickupItemName;
                currentRoom->pickupItem(inputPickupItemName, PlayerInventoryVectPtr);
                cout << endl;
                
                if(PlayerInventoryVectPtr.size() > 0) {
                    cout << "If you like to drop items please type item name and color. Otherwise, type No" << endl;
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
                
                cout << "Here are items in your inventory currently.." << endl;
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
                    cout << "CONGRATULATIONS!!! YOU WON THE ZUUL !!!" << endl;
                    break;
                }
                
                cout << "Alright!!! This room has the following exits leading to other rooms: " << endl;
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
                
                cout << "Type an exit letter and you go to corresponding room" << endl;
                cin >> inputExit;
                
                curRoomNum = currentRoom->getExitRoomNumber(inputExit);
                
            }
            
              
        }
    }
}

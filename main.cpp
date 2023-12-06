#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"


using namespace std;
void printExits(room* currentRoom);


int main (){

    cout << "Hello player. You are currently in Hogwarts castle, and Harry Potter needs your help! The notorious Dolores Umbridge has confiscated his broomstick, and he might be expelled if he's suspected of stealing it back from her. He needs you to find his broomstick and bring it back to him in the Great Hall. Good luck!" << endl;
  
    vector <room*> rooms;
    int inventory[6];
    for(int i = 0; i < 6; i++){
        inventory[i] = 0;
    }
    item* key = new item();
    item* broomstick = new item();
    item* candy = new item();
    item* cloak = new item();
    item* cakes = new item();
    item* potion = new item();
    room* entrance = new room();
    room* great_hall = new room();
    room* bridge = new room();
    room* hagrid_hut = new room();
    room* honeydukes = new room();
    room* hogsmeade = new room();
    room* shrieking_shack = new room();
    room* staircase = new room();
    room* corridor = new room();
    room* umbridge_office = new room();
    room* room_of_requirement = new room();
    room* umbridge_dungeon = new room();
    room* potion_room = new room();
    room* filch_office = new room();
    room* filch_secret_lair = new room();
    char direction[30];


    strcpy(entrance->name, "Entrance Hall");
    strcpy(entrance->description, "You are in the Entrance Hall. Go forth and find Harry's broomstick! Or, if you already have it, drop the broomstick in this room.");
    entrance->setExit(entrance->north, great_hall);
    entrance->setExit(entrance->south, bridge);

    strcpy(great_hall->name, "Great Hall");
    strcpy(great_hall->description, "You are in the Great Hall. Lots of good food over here!");
    great_hall->setExit(great_hall->south, entrance);
    great_hall->setExit(great_hall->west, staircase);


    strcpy(bridge->name, "Bridge");
    strcpy(bridge->description, "You are at the bridge. Keep going to move outside the castle");
    bridge->setExit(bridge->south, hagrid_hut);
    bridge->setExit(bridge->north, entrance);
    bridge->setExit(bridge->west, hogsmeade);

    strcpy(hagrid_hut->name, "Hagrid's Hut");
    strcpy(hagrid_hut->description, "You are in Hagrid's hut! He has some rock cakes you might be interested in. Don't forget to say 'hi' to Buckbeak.");
    hagrid_hut->setExit(hagrid_hut->north, bridge);
    hagrid_hut->item[0] = 1;


    strcpy(honeydukes->name, "Honeydukes");
    strcpy(honeydukes->description, "You are in Honeydukes, the famous candy shop. Acid Pops are highly discounted, want to take one? ");
    honeydukes->setExit(honeydukes->north, hogsmeade);

    honeydukes->item[1] = 1;


    strcpy(hogsmeade->name, "Hogsmeade");
    strcpy(hogsmeade->description, "You are in Hogsmeade, the famous village outside of Hogwarts. There are lots of great shops here. Feel free to explore! ");

    hogsmeade->setExit(hogsmeade->south, honeydukes);
    hogsmeade->setExit(hogsmeade->east, bridge);
    hogsmeade->setExit(hogsmeade->north, shrieking_shack);

    strcpy(shrieking_shack->name, "Shrieking Shack");
    strcpy(shrieking_shack->description, "You're in the Shrieking Shack. It's a little unnerving in here, I'd leave as soon as possible if I were you");
    shrieking_shack->setExit(shrieking_shack->south, hogsmeade);

    strcpy(staircase->name, "Staircase");
    strcpy(staircase->description, "You're in a staircase in Hogwarts ");
    staircase->setExit(staircase->east, great_hall);
    staircase->setExit(staircase->north, corridor);

    strcpy(corridor->name, "Corridor");
    strcpy(corridor->description, "You're in a corridor on one of the upper floors of the castle. Plenty of important-looking rooms up here... ");

    corridor->setExit(corridor->south, staircase);
    corridor->setExit(corridor->north, umbridge_office);
    corridor->setExit(corridor->east, room_of_requirement);


    strcpy(umbridge_office->name, "Umbridge's Office");
    strcpy(umbridge_office->description, "You're in Umbridge's office. Be careful, you don't want to get caught");
    umbridge_office->setExit(umbridge_office->south, corridor);
    umbridge_office->setExit(umbridge_office->east, umbridge_dungeon);

    strcpy(umbridge_dungeon->name, "Umbridge's Dungeon");
    strcpy(umbridge_dungeon->description, "Woah, Umbridge has a secret dungeon. There are two trolls here, luckily you have that invisibility cloak. And look, there's Harry's broomstick! You need to get that back to the Great Hall for him!");
    umbridge_dungeon->setExit(umbridge_dungeon->west, umbridge_office);
    umbridge_dungeon->item[5] = 1;


    strcpy(room_of_requirement->name, "Room of Requirement");
    strcpy(room_of_requirement->description, "You are in the Room of Requirement. You can think of anything that you need and the room will give it to you. Oh look, I think the room's found something for you...");

    room_of_requirement->setExit(room_of_requirement->west, corridor);
    room_of_requirement->setExit(room_of_requirement->east, potion_room);
    room_of_requirement->item[2] = 1;


    strcpy(potion_room->name, "Potions Room");
    strcpy(potion_room->description, "You're in the Potions Room. Looks like Fred and George are in here too. They look like they have something brewing over there that they'd like to give you...");
    potion_room->setExit(potion_room->west, room_of_requirement);
    potion_room->setExit(potion_room->south, filch_office);
    potion_room->item[3] = 1;


    strcpy(filch_office->name, "Filch's Office");
    strcpy(filch_office->description, "You are in Filch's office. Luckily he isn't here right now. You might want to slip that sleeping potion into his tea to make sure he doesn't catch you too quickly when he comes back");
    filch_office->setExit(filch_office->north, potion_room);
    filch_office->setExit(filch_office->south, filch_secret_lair);

    strcpy(filch_secret_lair->name, "Filch's Secret Lair");
    strcpy(filch_secret_lair->description, "You are in Filch's secret lair! And look, there's a key!");
    filch_secret_lair->setExit(filch_secret_lair->north, filch_office);
    filch_secret_lair->item[4] = 1;


    entrance->setInitialExit();
    great_hall->setInitialExit();
    bridge->setInitialExit();
    hagrid_hut->setInitialExit();
    honeydukes->setInitialExit();
    hogsmeade->setInitialExit();
    shrieking_shack->setInitialExit();
    staircase->setInitialExit();
    corridor->setInitialExit();
    umbridge_office->setInitialExit();
    room_of_requirement->setInitialExit();
    umbridge_dungeon->setInitialExit();
    potion_room->setInitialExit();
    filch_office->setInitialExit();
    filch_secret_lair->setInitialExit();




    rooms.push_back(entrance);
    rooms.push_back(bridge);
    rooms.push_back(hagrid_hut);
    rooms.push_back(great_hall);
    rooms.push_back(honeydukes);
    rooms.push_back(hogsmeade);
    rooms.push_back(shrieking_shack);
    rooms.push_back(staircase);
    rooms.push_back(corridor);
    rooms.push_back(umbridge_office);
    rooms.push_back(umbridge_dungeon);
    rooms.push_back(room_of_requirement);
    rooms.push_back(potion_room);
    rooms.push_back(filch_office);
    rooms.push_back(filch_secret_lair);

    room* currentRoom = entrance;

  bool running = true;
  while (running == true){
    cout << endl;
    cout << "What would you like to do? Type 'help' to see all commands" << endl;
    char userCommand [30];
    cin.get(userCommand, 30);
    cin.get();
    if(strcmp(userCommand, "help") == 0){
      cout << "Your commands are: help, go, inventory, get, drop, quit" << endl;
    

    }
    if(strcmp(userCommand, "go") == 0){
      cout << "Which direction would you like to go? north/south/east/west" << endl;
      bool validDirection = false;
      while(validDirection == false){
        char goDir [40];
        cin.get(goDir, 40);
        cin.get();
        if(strcmp(goDir, "north") == 0){
          if(currentRoom->roomsMap[currentRoom->north] != NULL){
            
            if(currentRoom->roomsMap[currentRoom->north] == umbridge_office && (inventory[4] !=1)){
                cout << "The door to Umbridge's office is locked. You're going to need a key to get in here" << endl;
            }
            else{
                currentRoom = currentRoom->roomsMap[currentRoom->north];
                cout << endl;
                cout << currentRoom->description << endl;
                cout << endl;
                printExits(currentRoom);
                cout << endl;
                currentRoom->printItems();
                validDirection = true;
            }

          }

        }
        else if(strcmp(goDir, "south") == 0){
          if(currentRoom->roomsMap[currentRoom->south] != NULL){

            if(currentRoom->roomsMap[currentRoom->south] == filch_office && (inventory[3] != 1)){
                cout << "You're going to need a sleeping potion before you enter Filch's office..." << endl;
            }
            else{
                currentRoom = currentRoom->roomsMap[currentRoom->south];
                cout << endl;
                cout << currentRoom->description << endl;
                cout << endl;
                printExits(currentRoom);
                cout << endl;
                currentRoom->printItems();
                validDirection = true;
            }

          }

        }
        else if(strcmp(goDir, "west") == 0){
          if(currentRoom->roomsMap[currentRoom->west] != NULL){
            currentRoom = currentRoom->roomsMap[currentRoom->west];
            cout << endl;
            cout << currentRoom->description << endl;
            cout << endl;
            printExits(currentRoom);
            cout << endl;
            currentRoom->printItems();
            validDirection = true;
          }
        }
        else if(strcmp(goDir, "east") == 0){
          if(currentRoom->roomsMap[currentRoom->east] != NULL){
            if(currentRoom->roomsMap[currentRoom->east] == potion_room && (inventory[0] != 1 || inventory[1] != 1)){
                cout << "Fred and George are in the Potions Room. They won't let you in unless you get them some sweets, preferably some candy and some rock cakes" << endl;
            }
            else{
                currentRoom = currentRoom->roomsMap[currentRoom->east];
                cout << endl;
                cout << currentRoom->description << endl;
                cout << endl;
                printExits(currentRoom);
                cout << endl;
                currentRoom->printItems();
                validDirection = true;
            }
            
          }
    
        }
    }
        
    }
    else if(strcmp(userCommand, "get")==0){
        cout << "What item would you like to pick up? " << endl;
        char itemPickUp [30];
        cin.get(itemPickUp, 30);
        cin.get();
        if(strcmp(itemPickUp, "cakes") == 0){
            if(currentRoom->item[0] == 1){
                
                currentRoom->item[0] = 0;
                inventory[0] = 1;

            }
            else{
                cout << "That item is not in this room " << endl;
            }
        }
        if(strcmp(itemPickUp, "candy") == 0){
            if(currentRoom->item[1] == 1){
                
                currentRoom->item[1] = 0;
                inventory[1] = 1;

            }
            else{
                cout << "That item is not in this room " << endl;
            }
        }
        if(strcmp(itemPickUp, "cloak") == 0){
            if(currentRoom->item[2] == 1){
                
                currentRoom->item[2] = 0;
                inventory[2] = 1;

            }
            else{
                cout << "That item is not in this room " << endl;
            }
        }
        if(strcmp(itemPickUp, "potion") == 0){
            if(currentRoom->item[3] == 1){
                
                currentRoom->item[3] = 0;
                inventory[3] = 1;

            }
            else{
                cout << "That item is not in this room " << endl;
            }
        }
        if(strcmp(itemPickUp, "key") == 0){
            if(currentRoom->item[4] == 1){
                
                currentRoom->item[4] = 0;
                inventory[4] = 1;

            }
            else{
                cout << "That item is not in this room " << endl;
            }
        }
        if(strcmp(itemPickUp, "broomstick") == 0){
            if(currentRoom->item[5] == 1){
                currentRoom->item[5] = 0;
                inventory[5] = 1;
            }
            else{
                cout << "That item is not in this room " << endl;
            }
        }

    }
    else if(strcmp(userCommand, "drop") == 0){
        cout << "What item would you like to drop? " << endl;
        char itemDrop[30];
        cin.get(itemDrop, 30);
        cin.get();
        if(strcmp(itemDrop, "cakes") == 0){
            if(inventory[0] == 1){
                currentRoom->item[0] = 1;
                inventory[0] = 0;

            }
            else{
                cout << "You do not have this item" << endl;
            }
        }
        if(strcmp(itemDrop, "candy") == 0){
            if(inventory[1] == 1){
                currentRoom->item[1] = 1;
                inventory[1] = 0;

            }
            else{
                cout << "You do not have this item" << endl;
            }
        }
        if(strcmp(itemDrop, "cloak") == 0){
            if(inventory[2] == 1){
                currentRoom->item[2] = 1;
                inventory[2] = 0;

            }
            else{
                cout << "You do not have this item" << endl;
            }
        }
        if(strcmp(itemDrop, "potion") == 0){
            if(inventory[3] == 1){
                currentRoom->item[3] = 1;
                inventory[3] = 0;

            }
            else{
                cout << "You do not have this item" << endl;
            }
        }
        if(strcmp(itemDrop, "key") == 0){
            if(inventory[4] == 1){
                currentRoom->item[4] = 1;
                inventory[4] = 0;

            }
            else{
                cout << "You do not have this item" << endl;
            }
        }
        if(strcmp(itemDrop, "broomstick") == 0){
            if(inventory[5] == 1){
                currentRoom->item[5] = 1;
                inventory[5] = 0;

            }
            if(strcmp(currentRoom->name, "Great Hall") == 0){
                cout << endl;
                cout << "YOU WIN!!!" << endl;
                running = false;
            }
            else{
                cout << "You do not have this item" << endl;
            }
        }
    }
    else if(strcmp(userCommand, "inventory") == 0){
        cout << "Inventory: " << endl;
        cout << endl;
        if(inventory[0] == 1){
            cout << "cakes" << endl;
        }
        if(inventory[1] == 1){
            cout << "candy" << endl;

        }
        if(inventory[2] == 1){
            cout << "cloak" << endl;
        }
        if(inventory[3] == 1){
            cout << "potion" << endl;
        }
        if(inventory[4] == 1){
            cout << "key" << endl;
        }
        if(inventory[5] == 1){
            cout << "broomstick" << endl;
        }
    }
    else if(strcmp(userCommand, "quit") == 0){
        running = false;
    }
    
    }

  }
  void printExits(room* currentRoom){
    cout << "Exits: " << endl;
    if(currentRoom->roomsMap[currentRoom->west] != NULL){
        cout << "west" << endl;
    }
    if(currentRoom->roomsMap[currentRoom->north] != NULL){
        cout << "north" << endl;
    }
    if(currentRoom->roomsMap[currentRoom->south] != NULL){
        cout << "south" << endl;
    }
    if(currentRoom->roomsMap[currentRoom->east] != NULL){
        cout << "east" << endl;
    }

  }








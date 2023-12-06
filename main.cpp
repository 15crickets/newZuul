#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"




using namespace std;


int main (){
  
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

    hagrid_hut->setExit(hagrid_hut->north, bridge);
    hagrid_hut->item[0] = 1;


    strcpy(honeydukes->name, "Honeydukes");
    honeydukes->setExit(honeydukes->north, hogsmeade);

    honeydukes->item[1] = 1;


    strcpy(hogsmeade->name, "Hogsmeade");

    hogsmeade->setExit(hogsmeade->south, honeydukes);
    hogsmeade->setExit(hogsmeade->east, bridge);
    hogsmeade->setExit(hogsmeade->north, shrieking_shack);

    strcpy(shrieking_shack->name, "Shrieking Shack");
    shrieking_shack->setExit(shrieking_shack->south, hogsmeade);

    strcpy(staircase->name, "Staircase");
    staircase->setExit(staircase->east, great_hall);
    staircase->setExit(staircase->north, corridor);

    strcpy(corridor->name, "Corridor");
    corridor->setExit(corridor->south, staircase);
    corridor->setExit(corridor->north, umbridge_office);
    corridor->setExit(corridor->east, room_of_requirement);


    strcpy(umbridge_office->name, "Umbridge's Office");
    umbridge_office->setExit(umbridge_office->south, corridor);
    umbridge_office->setExit(umbridge_office->east, umbridge_dungeon);

    strcpy(umbridge_dungeon->name, "Umbridge's Dungeon");
    umbridge_dungeon->setExit(umbridge_dungeon->west, umbridge_office);
    umbridge_dungeon->item[5] = 1;


    strcpy(room_of_requirement->name, "Room of Requirement");
    room_of_requirement->setExit(room_of_requirement->west, corridor);
    room_of_requirement->setExit(room_of_requirement->east, potion_room);
    room_of_requirement->item[2] = 1;


    strcpy(potion_room->name, "Potion's Room");
    potion_room->setExit(potion_room->west, room_of_requirement);
    potion_room->setExit(potion_room->south, filch_office);
    potion_room->item[3] = 1;


    strcpy(filch_office->name, "Filch's Office");
    filch_office->setExit(filch_office->north, potion_room);
    filch_office->setExit(filch_office->south, filch_secret_lair);

    strcpy(filch_secret_lair->name, "Filch's Secret Lair");
    filch_secret_lair->setExit(filch_secret_lair->north, filch_office);
    potion_room->item[4] = 1;


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

    room* currentRoom = honeydukes;

  bool running = true;
  while (running == true){
    cout << "What would you like to do? Type 'help' to see all commands" << endl;
    char userCommand [30];
    cin.get(userCommand, 30);
    cin.get();
    //help go inventory get drop quit
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
            currentRoom = currentRoom->roomsMap[currentRoom->north];
            cout << "Place: " << currentRoom->name << endl;
            cout << endl;
            currentRoom->printItems();
            validDirection = true;
          }
        }
        else if(strcmp(goDir, "south") == 0){
          if(currentRoom->roomsMap[currentRoom->south] != NULL){
            currentRoom = currentRoom->roomsMap[currentRoom->south];
            cout << "Place: " << currentRoom->name << endl;
            cout << endl;
            currentRoom->printItems();
            validDirection = true;
          }

        }
        else if(strcmp(goDir, "west") == 0){
          if(currentRoom->roomsMap[currentRoom->west] != NULL){
            currentRoom = currentRoom->roomsMap[currentRoom->west];
            cout << "Place: " << currentRoom->name << endl;
            cout << endl;
            currentRoom->printItems();
            validDirection = true;
          }
        }
        else if(strcmp(goDir, "east") == 0){
          if(currentRoom->roomsMap[currentRoom->east] != NULL){
            currentRoom = currentRoom->roomsMap[currentRoom->east];
            cout << "Place: " << currentRoom->name << endl;
            cout << endl;
            currentRoom->printItems();
            validDirection = true;
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
            else{
                cout << "You do not have this item" << endl;
            }
        }
    }
    else if(strcmp(userCommand, "inventory")){
        cout << "Inventory" << endl;
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
    
    }




  }








#include <iostream>
#include <cstring>
#include <map>
#include "room.h"
#include "item.h"
using namespace std;


room::room(){
    for(int i = 0; i < 6; i++){
        item[i] = 0;
    }
  north = new char [10];
  south = new char [10];
  east = new char [10];
  west = new char[10];
  strcpy(north, "north");
  strcpy(south, "south");
  strcpy(west, "west");
  strcpy(east, "east");
  
  key = new char[30];
  cakes = new char[30];
  candy = new char[30];
  potion = new char [30];
  cloak = new char [30];
  broomstick = new char[30];
  strcpy(key, "key");
  strcpy(cakes, "cakes");
  strcpy(candy, "candy");
  strcpy(potion, "potion");
  strcpy(cloak, "cloak");
  strcpy(broomstick, "broomstick");

}
void room::setInitialExit(){

  if(roomsMap.find(north) == roomsMap.end()){
    roomsMap.insert(pair<char*, room*> (north, NULL));
  }

  if(roomsMap.find(south) == roomsMap.end()){
    roomsMap.insert(pair<char*, room*> (south, NULL));
  }

  if(roomsMap.find(east) == roomsMap.end()){
    roomsMap.insert(pair<char*, room*> (east, NULL));
  }

  if(roomsMap.find(west) == roomsMap.end()){
    roomsMap.insert(pair<char*, room*> (west, NULL));
  }
}
void room::setExit(char* dir, room* tempRoom){
  

  roomsMap.insert(pair<char*, room*> (dir, tempRoom));


}
void room::printItems(){
    cout << "Items: " << endl;

    if(item[0] == 1){
        cout << "cakes" << endl;
    }
    if(item[1] == 1){
        cout << "candy" << endl;

    }
    if(item[2] == 1){

        cout << "cloak" << endl;
    }
    if(item[3] == 1){
        cout << "potion" << endl;
    }
    if(item[4] == 1){
        cout << "key" << endl;
    }
    if(item[5] == 1){
        cout << "broomstick" << endl;
    }

}

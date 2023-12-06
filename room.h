#ifndef ROOM_H
#define ROOM_H
//room.h file
#include <iostream>
#include <cstring>
#include <map>
#include "item.h"



using namespace std;
//room class
class room{
  public:

    //constructor
    room(); 
    //initialization of various char pointers
    char* north;
    char* south;
    char* west;
    char* east;

    char* key;
    char* potion;
    char* cakes;
    char* candy;
    char* cloak;
    char* broomstick;
    //function prototypes
    void setExit(char* dir, room* tempRoom);
    void setInitialExit();
    void printItems();
    //important arrays: name, description, and items
    char name[40];
    char description[1000];
    int item[6];
    //map, where exits are stored
    map <char*, room*> roomsMap;


};

#endif
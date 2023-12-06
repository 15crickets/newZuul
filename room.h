#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <map>
#include "item.h"




using namespace std;
class room{
  public:

    room(); 
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

    void setExit(char* dir, room* tempRoom);
   
    void setInitialExit();
    void printItems();
    char name[40];
    char description[1000];
    int item[6];
    map <char*, room*> roomsMap;


};

#endif
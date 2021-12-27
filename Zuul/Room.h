#pragma once
#include <iostream>
#include <cstring>
using namespace std;


struct item{
    char name[];
    char color[];
};



class Room {
  public:
    Room();
    ~Room();
    
    
    
  protected:
    int roomNumber;
    char roomDescription[];
    vector<item*>itemptr;
};

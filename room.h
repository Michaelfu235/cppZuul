#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class room{
 public:
  room(int m, char* n, vector<item*> l, map<char,int> e);

  int id;
  char* name;
  vector<item*> items;
  map<char,int> exits;


  virtual int getID();
  virtual void printRoom();
};
#endif

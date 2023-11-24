#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"

using namespace std;

class room{
 public:
  room(int m, char* n, vector<item*> l, vector<bool> e);

  int id;
  char* name;
  vector<item*> items;
  vector<bool> exits;


  virtual int getID();
  virtual void printRoom();
};
#endif

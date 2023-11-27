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
  room(int m, char* n, char* d, vector<item*> l, map<char,int> e);

  int id;
  char* name;
  char* description;
  vector<item*> items;
  map<char,int> exits;


  virtual int getID();
  virtual void printRoom();
  virtual void removeItem(char nme[]);
  virtual void addItem(char* nme);
  virtual int exitRoom(char gotoo[]);
  virtual bool findItem(char* lookingfor);
};
#endif

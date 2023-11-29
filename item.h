//Author: Michael Fu
//Date: 11/29
//this is the header file for the item class

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

class item{
 public:
  item(char* namae);

  //initialize variables and functions
  char* itemName;
  virtual char* getItemName();
};
#endif

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

class item{
 public:
  item(char* namae);

  char* itemName;
  virtual char* getItemName();
};
#endif

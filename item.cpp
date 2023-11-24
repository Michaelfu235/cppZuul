#include <iostream>
#include "item.h"

using namespace std;

item::item(char* namae){
  itemName = new char[80];
  strcpy(itemName, namae);
}

char* item::getItemName(){
  return itemName;
}

//Author: Michael Fu
//Date: 11/29
//This is the cpp file for the item class

#include <iostream>
#include "item.h"

using namespace std;

item::item(char* namae){
  //create a char array of the name, and set the variable
  itemName = new char[80];
  strcpy(itemName, namae);
}

char* item::getItemName(){
  //return the item name
  return itemName;
}

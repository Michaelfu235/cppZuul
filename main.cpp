#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

int main(){
  char* namee = new char[10];
  strcpy(namee, "testing");
  vector<item*> itemstest;
  char* namae = new char[10];
  strcpy(namae, "testing2");
  item* temp = new item(namae);
  itemstest.push_back(temp);
  vector<bool> exitstest{true, false, false, true};
  room* test = new room(0, namee, itemstest, exitstest);
  test->printRoom();
}

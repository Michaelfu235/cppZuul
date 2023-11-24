#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

room::room(int m, char* n, vector<item*> l, vector<bool> e){
  name = new char[80];
  strcpy(name, n);
  id = m;
  exits = e;
  items = l;
}

int room::getID(){
  return id;
  
}

void room::printRoom(){
  cout << "You are in room " << name << endl;
  cout << "Exits: " << endl;
  if(exits[0] == true){
    cout << "NORTH" << endl;
  }
  if(exits[1] == true){
    cout << "EAST" << endl;
  }
  if(exits[2] == true){
    cout << "SOUTH" << endl;
  }
  if(exits[3] == true){
    cout << "WEST" << endl;
  }
  cout << endl;
  if(items.size() > 0){
    cout << "Items: " << endl;
    for(int i = 0;i<items.size();i++){
      cout << items[i]->getItemName() << " ";
      
    }
    cout << endl;
  } else {
    cout << "No items in the room" << endl;
  }
}

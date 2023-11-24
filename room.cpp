#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include "room.h"
#include "item.h"

using namespace std;

room::room(int m, char* n, vector<item*> l, map<char,int> e){
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
  map<char, int>::iterator itr;
  for(itr=exits.begin(); itr!=exits.end(); ++itr){
    if(itr->first=='N'){
      cout << "NORTH ";
    } else if(itr->first=='E'){
      cout << "EAST ";
    } else if(itr->first=='S'){
      cout << "SOUTH ";
    } else{
      cout << "WEST ";
    }
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

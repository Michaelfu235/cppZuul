#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include "room.h"
#include "item.h"

using namespace std;

room::room(int m, char* n, char* d, vector<item*> l, map<char,int> e){
  name = new char[80];
  strcpy(name, n);
  id = m;
  description = new char[200];
  strcpy(description, d);
  exits = e;
  items = l;
}

int room::getID(){
  return id;
  
}

void room::printRoom(){
  cout << "You are in room " << name << endl;
  cout << description << endl;
  cout << endl;
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
  cout << endl;
}


void room::removeItem(char nme[]){
  for(int i = 0;i<items.size();i++){
    if(strcmp(items[0]->getItemName(),nme)==0){
      items.erase(items.begin()+i);
    }
  }
}

void room::addItem(char* nme){
  item* newItem = new item(nme);
  items.push_back(newItem);
}

int room::exitRoom(char gotoo[]){
  map<char, int>::iterator it;
  
  for(it = exits.begin();it!=exits.end();++it){
    if(it->first == gotoo[0]){
      return(it->second);
    }
  }
  return -1;
}

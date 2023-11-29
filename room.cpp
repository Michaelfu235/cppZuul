//Author: Michael Fu
//Date: 11/29
//This is the cpp file for the room class for Zuul.

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include "room.h"
#include "item.h"

using namespace std;


room::room(int m, char* n, char* d, vector<item*> l, map<char,int> e){
  //initialize the funtions and variables
  name = new char[80];
  strcpy(name, n);
  id = m;
  description = new char[200];
  strcpy(description, d);
  exits = e;
  items = l;
}

int room::getID(){
  //return the id when called
  return id;
  
}

void room::printRoom(){
  //go through the room and print the name, description, and exits. Then go through the items and print all the items. If there are no items, print that there are not items. 
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
      cout << i+1 << ") " << items[i]->getItemName() << endl;
      
    }
    cout << endl;
  } else {
    cout << "No items in the room" << endl;
  }
  cout << endl;
}


void room::removeItem(char nme[]){
  //remove items from the room. 
  for(int i = 0;i<items.size();i++){
    if(strcmp(items[0]->getItemName(),nme)==0){
      items.erase(items.begin()+i);
    }
  }
}

void room::addItem(char* nme){
  //add items to the room after creating a new item with the given name
  item* newItem = new item(nme);
  items.push_back(newItem);
}

int room::exitRoom(char gotoo[]){
  //for exit room, go through the exits and if it is the one the user wants, then return the id of the room that the exit leads to. Otherwise, return -1;
  map<char, int>::iterator it;
  
  for(it = exits.begin();it!=exits.end();++it){
    if(it->first == gotoo[0]){
      return(it->second);
    }
  }
  return -1;
}

bool room::findItem(char* lookingfor){
  //if the item exists in the room, return true. otherwise, return false;
  int temp = items.size();
  for(int i = 0;i<items.size();i++){
    if(strcmp(lookingfor, items[i]->getItemName())==0){
      return true;
    }
  }
  return false;
}

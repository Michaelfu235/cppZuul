#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;


void goo(int &current, vector<room*> &rooms, char gotoo[]);
void get(int current, vector<room*> &rooms, char getting[], vector<item*> &inventory);

int main(){
  vector<room*> rooms;
  vector<char*> inventory;
  bool justKeepGoing=true;
  char input[80];
  int currentRoom = 0;
  
  //creating the rooms :\
  //1-20 lab

  char* onetwentyname = new char[10];
  strcpy(onetwentyname,"1-20");
  char* onetwentydescription = new char[200];
  strcpy(onetwentydescription,"You are currently in the 1-20 lab at Sunset.  All the cool people are hanging out here.");
  map<char,int> onetwentyexits;
  onetwentyexits['N'] = 1;
  onetwentyexits['E'] = 2;
  onetwentyexits['S']=3;
  onetwentyexits['W']=4;
  vector<item*> onetwentyitems;
  room* onetwenty = new room(0,onetwentyname,onetwentydescription, onetwentyitems, onetwentyexits);
  char* onetwentyitem = new char[10];
  strcpy(onetwentyitem,"map");
  onetwenty->addItem(onetwentyitem);

  rooms.push_back(onetwenty);



  //north
  char* northname = new char[10];
  strcpy(northname, "north");
  char* northdes = new char[100];
  strcpy(northdes, "this room is north of 1-20");
  map<char, int> northexits;
  northexits['N']=5;
  northexits['S']=0;
  vector<item*> northitems;

  room* north = new room(1, northname, northdes, northitems, northexits);
  char* northpol = new char[15];
  strcpy(northpol, "north pole");
  north->addItem(northpol);
  rooms.push_back(north);
  
  
  //south
  char* southname = new char[10];
  strcpy(southname, "south");
  char* southdes = new char[100];
  strcpy(southdes, "this room is south of 1-20");
  map<char, int> southexits;
  southexits['S']=6;
  southexits['N']=0;
  vector<item*> southitems;

  room* south = new room(3, southname, southdes, southitems, southexits);
  char* southpol = new char[15];
  strcpy(southpol, "south pole");
  south->addItem(southpol);
  rooms.push_back(south);


  //east
  char* eastname = new char[10];
  strcpy(eastname, "east");
  char* eastdes = new char[100];
  strcpy(eastdes, "this room is east of 1-20");
  map<char, int> eastexits;
  eastexits['E']=7;
  eastexits['W']=0;
  vector<item*> eastitems;

  room* east = new room(2, eastname, eastdes, eastitems, eastexits);
  char* eastsunrise = new char[30];
  strcpy(eastsunrise, "the sunrise from the east");
  east->addItem(eastsunrise);
  rooms.push_back(east);
  
  
  //west
  char* westname = new char[10];
  strcpy(westname, "west");
  char* westdes = new char[100];
  strcpy(westdes, "this room is west of 1-20");
  map<char, int> westexits;
  westexits['W']=8;
  westexits['E']=0;
  vector<item*> westitems;

  room* west = new room(4, westname, westdes, westitems, westexits);
  rooms.push_back(west);
	 
  for(int i = 0;i<rooms.size();i++){
    rooms[i]->printRoom();
  }

  
  cout << currentRoom << endl;

  char temporary[] = "NORTH";
  goo(currentRoom, rooms, temporary);

  cout << currentRoom << endl;

  char temporary2[] = "WEST";
  goo(currentRoom, rooms, temporary2);

  cout << currentRoom << endl;
}



void goo(int &current, vector<room*> &rooms, char gotoo[]){
  char where = gotoo[0];
  if(rooms[current]->exitRoom(gotoo) != -1){
    current = rooms[current]->exitRoom(gotoo);

  } else {
    cout << "that is not a valid exit." << endl;
  }
}



void get(int current, vector<room*> &rooms, char getting[], vector<char*> &inventory){
  char* lookingfor = new char[20];
  strcpy(lookingfor, getting);
  if(rooms[current]->findItem(lookingfor)==true){
    rooms[current]->removeItem(getting);
    inventory.push_back(lookingfor);
    cout << lookingfor << " has been added to your inventory. " << endl;
  } else {
    cout << "This item either does not exist or is not in this room. " << endl;
  }
}

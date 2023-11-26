#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

int main(){
  vector<room*> rooms;
  vector<item*> inventory;
  bool justKeepGoing=true;
  char input[80];

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
  char* northdes = new char[200];
  strcpy(northdes, "this room is north of 1-20");
  map<char, int> northexits;
  northexits['N']=5;
  vector<item*> northitems;

  room* north = new room(1, northname, northdes, northitems, northexits);
  char* northpol = new char[15];
  strcpy(northpol, "north pole");
  north->addItem(northpol);


  //south
  char* southname = new char[10];
  strcpy(southname, "south");
  char* southdes = new char[200];
  strcpy(southdes, "this room is south of 1-20");
  map<char, int> southexits;
  southexits['S']=6;
  vector<item*> southitems;

  room* south = new room(3, southname, southdes, southitems, southexits);
  char* southpol = new char[15];
  strcpy(southpol, "south pole");
  south->addItem(southpol);

  south->printRoom();


  
  rooms[0]->printRoom();


  
  char* namee = new char[10];
  strcpy(namee, "testing");
  vector<item*> itemstest;
  char* namae = new char[10];
  strcpy(namae, "testing2");
  item* temp = new item(namae);
  itemstest.push_back(temp);
  map<char, int> testexits;
  testexits['E']=1;
  testexits['N']=5;
  char* descriptii = new char[200];
  strcpy(descriptii,"This is the testing room hopefully it works or smth :) idk!");
  char* testing3 = new char[15];
  strcpy(testing3, "alhoeubat");
  char* rando = new char[16];
  strcpy(rando, "testing2");
  
  room* test = new room(0, namee, descriptii, itemstest, testexits);
  test->removeItem(rando);
  test->addItem(testing3);
  test->printRoom();
}

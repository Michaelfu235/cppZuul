#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;


void goo(int &current, vector<room*> &rooms, char gotoo[]);
void get(int current, vector<room*> &rooms, char getting[], vector<char*> &inventory);
void drop(int current, vector<room*> &rooms, char dropping[], vector<char*> &inventory);

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
  northexits['E']=9;
  northexits['W']=16;
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
  southexits['W']=11;
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
  eastexits['N']=9;
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
  westexits['N']=16;
  westexits['S']=11;
  vector<item*> westitems;

  room* west = new room(4, westname, westdes, westitems, westexits);
  rooms.push_back(west);


  //northnorth
  char* northnorthname = new char[20];
  strcpy(northnorthname, "northnorth");
  char* northnorthdes = new char[100];
  strcpy(northnorthdes, "This room is north of north of 1-20");
  map<char, int> northnorthexits;
  northnorthexits['S']=1;
  northnorthexits['E']=10;
  vector<item*> northnorthitems;

  room* northnorth = new room(5, northnorthname, northnorthdes, northnorthitems, northnorthexits);
  rooms.push_back(northnorth);


  //northeast
  char* northeastname = new char[20];
  strcpy(northeastname, "northeast");
  char* northeastdes = new char[100];
  strcpy(northeastdes, "This room is northeast of 1-20.");
  map<char, int> northeastexits;
  northeastexits['N']=10;
  northeastexits['S']=2;
  northeastexits['W']=1;
  vector<item*> northeastitems;

  room* northeast = new room(9, northeastname, northeastdes, northeastitems, northeastexits);
  rooms.push_back(northeast);


  //northnortheast;
  char* northnortheastname = new char[20];
  strcpy(northnortheastname, "northnortheast");
  char* northnortheastdes = new char[100];
  strcpy(northnortheastdes, "This room is north of northeast of 1-20.");
  map<char, int> northnortheastexits;
  northnortheastexits['S']=9;
  northnortheastexits['W']=5;
  vector<item*> northnortheastitems;

  room* northnortheast = new room[10, northnortheastname, northnortheastdes, northnortheastitems, northnortheastexits);
  rooms.push_back(northnortheast);


  //northwest
  char* northwestname = new char[10];
  strcpy(northwestname, "northwest");
  char* northwestdes = new char[100];
  strcpy(northwestdes, "This room is northwest of 1-20.");
  map<char, int> northwestexits;
  northwestexits['E']=1;
  northwestexits['S']=4;
  vector<item*> northwestitems;

  room* northwest = new room(16, northwestname, northwestdes, northwestitems, northwestexits);
  char* spaceneedle = new char[30];
  strcpy(spaceneedle, "seattle space needle");
  northwest.addItem(spaceneedle);
  rooms.push_back(northwest);


  //westwest
  char* westwestname = new char[10];
  strcpy(westwestname, "westwest");
  char* westwestdes = new char[100];
  strcpy(westwestdes, "This room is west of west of 1-20.");
  map<char, int> westwestexits;
  westwestexits['E']=4;
  westwestexits['S']=12;
  vector<item*> westwestitems;
  
  room* westwest = new room(8, westwestname, westwestdes, westwestitems, westwestexits);
  char* lasso = new char[30];
  strcpy(lasso, "lasso of the wild west");
  westwest->addItem(lasso);
  rooms.push_back(westwest);


  //easteast
  char* easteastname = new char[10];
  strcpy(easteastname, "easteast");
  char* easteastdes = new char[100];
  strcpy(easteastdes, "This room is east of east of 1-20");
  map<char, int> easteastexits;
  easteastexits['W']=2;
  easteastexits['S']=15;
  vector<item*> easteastitems;

  room* easteast = new room(7, easteastname, easteastdes, easteastitems, easteastexits);
  rooms.push_back(easteast);


  //southwest
  char* southwestname = new char[10];
  strcpy(southwestname, "southwest");
  char* southwestdes = new char[100];
  strcpy(southwestdes, "This room is southwest of 1-20.");
  map<char, int> southwestexits;
  southwestexits['N']=4;
  southwestexits['E']=3;
  southwestexits['S']=13;
  southwestexits['W']=12;
  vector<item*> southwestitems;

  room* southwest = new room(11, southwestname, southwestdes, southwestitems, southwestexits);
  rooms.push_back(southwest);


  //southwestwest
  char* southsouthwestname = new char[20];
  strcpy(southsouthwestname, "southsouthwest");
  char* southsouthwestdes = new char[100];
  strcpy(southsouthwestdes, "This room is south of southwest of 1-20.");
  map<char, int> southsouthwestexits;
  southsouthwestexits['N']=8;
  southsouthwestexits['E']=11;
  southsouthwestexits['S']=14;
  vector<item*> southsouthwestitems;

  room* southsouthwest = new room(12, southsouthwestname, southsouthwestdes, southsouthwestitems, southsouthwestexits);
  rooms.push_back(southsouthwest);


  //southsouthwestwest
  char* southsouthwestwestname = new char[25];
  strcpy(southsouthwestwestname, "southsouthwestwest");
  char* southsouthwestwestdes = new char[100];
  strcpy(southsouthwestwestdes, "This room is southwest of southwest of 1-20.");
  map<char, int> southsouthwestwestexits;
  southsouthwestwestexits['N']=12;
  southsouthwestwestexits['E']=13;
  vector<item*> southsouthwestwestitems;

  room* southsouthwestwest = new room(14, southsouthwestwestname, southsouthwestwestdes, southsouthwestwestitems, southsouthwestwestexits);
  rooms.push_back(southsouthwestwest);

  
  
  /*
  
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

  char getts[] = "north pole";
  get(currentRoom, rooms, getts, inventory);

  for(int i = 0;i<inventory.size();i++){
    cout << inventory[i] << endl;
  }

  rooms[currentRoom]->printRoom();

  char temporary3[] = "SOUTH";
  char temporary4[] = "north pole";
  
  goo(currentRoom, rooms, temporary3);

  rooms[currentRoom]->printRoom();
  drop(currentRoom, rooms, temporary4, inventory);

  rooms[currentRoom]->printRoom();
  */
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


void drop(int current, vector<room*> &rooms, char dropping[], vector<char*> &inventory){
  char* drop = new char[10];
  strcpy(drop, dropping);
  for(int i = 0;i<inventory.size();i++){
    if(strcmp(inventory[i],drop)==0){
      rooms[current]->addItem(drop);
      inventory.erase(inventory.begin() + i);
      cout << drop << " has been dropped from your inventory into the room." << endl;
      return;
    }
  }
  cout << drop << " is not in your inventory. " << endl;
}

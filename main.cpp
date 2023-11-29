/*Author: Michael Fu
 *Date: 11/29
 *Description: This is the CPP of the game Zuul, where players can enter rooms and pick up or drop items. 
 */


#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

//initialize the functions
void goo(int &current, vector<room*> &rooms, char gotoo[]);
void get(int current, vector<room*> &rooms, char getting[], vector<char*> &inventory);
void drop(int current, vector<room*> &rooms, char dropping[], vector<char*> &inventory);

int main(){
  //create the vector of rooms, the inventory, and other useful variables
  vector<room*> rooms;
  vector<char*> inventory;

  bool justKeepGoing=true;
  bool playerwins;
  char input[80];
  int currentRoom = 0;

  //creating the rooms :\
  //For each of the rooms, initialize two character arrays for the name and description of each room, a map of characters and ints for the exits, and a vector of items for the rooms. Then, if the room has an item, add the item to the room and push the finalized room back into the vector of rooms. 
  
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
  strcpy(onetwentyitem,"MAP");
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
  strcpy(northpol, "NORTH POLE");
  north->addItem(northpol);
  rooms.push_back(north);


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
  strcpy(eastsunrise, "PICTURE OF THE SUNRISE");
  east->addItem(eastsunrise);
  rooms.push_back(east);

  
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
  strcpy(southpol, "SOUTH POLE");
  south->addItem(southpol);
  rooms.push_back(south);



  
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


  //southsouth
  char* southsouthname = new char[20];
  strcpy(southsouthname, "southsouth");
  char* southsouthdes = new char[100];
  strcpy(southsouthdes, "This room is south of south of 1-20.");
  map<char, int> southsouthexits;
  southsouthexits['W'] = 13;
  southsouthexits['N']=3;
  southsouthexits['E']=15;
  vector<item*> southsouthitems;

  room* southsouth = new room(6, southsouthname, southsouthdes, southsouthitems, southsouthexits);
  rooms.push_back(southsouth);


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
  strcpy(lasso, "LASSO");
  westwest->addItem(lasso);
  rooms.push_back(westwest);
  

  
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

  room* northnortheast = new room(10, northnortheastname, northnortheastdes, northnortheastitems, northnortheastexits);
  rooms.push_back(northnortheast);


 
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
  char* southwestwestname = new char[20];
  strcpy(southwestwestname, "southsouthwest");
  char* southwestwestdes = new char[100];
  strcpy(southwestwestdes, "This room is west of southwest of 1-20.");
  map<char, int> southwestwestexits;
  southwestwestexits['N']=8;
  southwestwestexits['E']=11;
  southwestwestexits['S']=14;
  vector<item*> southwestwestitems;

  room* southwestwest = new room(12, southwestwestname, southwestwestdes, southwestwestitems, southwestwestexits);
  rooms.push_back(southwestwest);



  //southsouthwest
  char* southsouthwestname = new char[20];
  strcpy(southsouthwestname, "southsouthwest");
  char* southsouthwestdes = new char[100];
  strcpy(southsouthwestdes, "This room is south of southwest of 1-20.");
  map<char, int> southsouthwestexits;
  southsouthwestexits['N']=11;
  southsouthwestexits['W']=14;
  southsouthwestexits['E']=6;
  vector<item*> southsouthwestitems;
  
  room* southsouthwest = new room(13, southsouthwestname, southsouthwestdes, southsouthwestitems, southsouthwestexits);
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



    //southsoutheasteast
  char* southsoutheasteastname = new char[25];
  strcpy(southsoutheasteastname, "southsoutheasteast");
  char* southsoutheasteastdes = new char[100];
  strcpy(southsoutheasteastdes, "This room is southeast of southeast of 1-20.");
  map<char, int> southsoutheasteastexits;
  southsoutheasteastexits['N']=7;
  southsoutheasteastexits['W']=6;
  vector<item*> southsoutheasteastitems;

  room* southsoutheasteast = new room(15, southsoutheasteastname, southsoutheasteastdes, southsoutheasteastitems, southsoutheasteastexits);
  rooms.push_back(southsoutheasteast);

  
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
  strcpy(spaceneedle, "NEEDLE");
  northwest->addItem(spaceneedle);
  rooms.push_back(northwest);


				      
    
    
  

  cout << "This is a game of Zuul!" << endl;
  cout << "Collect every single item that is out there to win the game!" << endl;
  cout << "The commands:" << endl;
  cout << "Enter 'GO [one of the exits]' to go through an exit" << endl;
  cout << "Enter 'GET [name of the item]' to pick an item up" << endl;
  cout << "Enter 'DROP [name of the item]' to drop an item" << endl;
  cout << "Enter 'INVENTORY' to check what items you have" << endl;
  cout << "Enter 'HELP' to see these commands again" << endl;
  cout << "Enter 'QUIT' to end the game" << endl;

   cout << "--------------------------------------------------------------------" \
<< endl;

  
  cout << endl;
  rooms[0]->printRoom();
   cout << "--------------------------------------------------------------------" \
<< endl;


  
  while(justKeepGoing == true){

    //create character arrays for the two parts of the input, and split them up b by going through the input until we reach a space or the end of the input, and keeping track of the index of the space/end
    //Then, set firstword to the input up until the index and secondword to everything after the index. 

    char firstword[40];
    char secondword[40];
    cin.get(input, 80);
    cin.get();
    int tempi = 0;
    for(tempi = 0;tempi<strlen(input);tempi++){
      firstword[tempi]=input[tempi];
      if(input[tempi+1]==' ' || input[tempi+1]=='\0'){
	break;
      }
    }
    firstword[tempi+1]='\0';

    int x = 0;
    int y = 0;
    for(x = tempi+2;x<strlen(input);x++){
      secondword[y]=input[x];
      y++;
      if(input[x+1]=='\0'){
	break;
      }
    }
    secondword[y]='\0';


    //if the firstword is go, call the go function and print the information of the new room we are in. 

    if(strcmp(firstword, "GO")==0){
      goo(currentRoom, rooms, secondword);
      rooms[currentRoom]->printRoom();
    }
    //if the firstword is get, call the get function
    if(strcmp(firstword, "GET")==0){
      get(currentRoom, rooms, secondword, inventory);
    }
    if(strcmp(firstword, "DROP")==0){
      //if the firstword is drop, call the drop function
      drop(currentRoom, rooms, secondword, inventory);
    }
    if(strcmp(firstword, "INVENTORY")==0){
      //if the first(and only) word is inventory, then go through the inventory and print out each element. 
      if(inventory.size()!=0){
	for(int i = 0;i<inventory.size();i++){
	  cout << inventory[i] << ", ";
	}
	cout << endl;
      }else{
	//if there is nothing in the inventory, print so
	cout << "no items in inventory" << endl;
      }
      c
    }
    if(strcmp(firstword, "QUIT")==0){
      //if the firstword is quit, set the justkeepgoing to false so the loop stops
      justKeepGoing = false;
    }
    if (strcmp(firstword, "HELP")==0){
      //if the word is help, print out all of the commands
      cout << "The commands:" << endl;
      cout << "Enter 'GO [one of the exits]' to go through an exit" << endl;
      cout << "Enter 'GET [name of the item]' to pick an item up" << endl;
      cout << "Enter 'DROP [name of the item]' to drop an item" << endl;
      cout << "Enter 'INVENTORY' to check what items you have" << endl;
      cout << "Enter 'HELP' to see these commands again" << endl;
      cout << "Enter 'QUIT' to end the game" << endl;
    }
    if((strcmp(firstword, "HELP")!=0) && (strcmp(firstword, "QUIT")!=0) && (strcmp(firstword, "INVENTORY")!=0) && (strcmp(firstword, "DROP")!=0) && (strcmp(firstword, "GET")!=0) && (strcmp(firstword, "GO")!=0)){
      //if the firstword was none of the commands, print out not a valid command. 
      cout << "Not a valid command. Remember to use all caps." << endl;
    }

    if(inventory.size()==5){
      //if the inventory size is 5(collected all the items) then print that they won and break the while loop. 
      cout << "Congrats! You have won the game!" << endl;
      justKeepGoing=false;
      break;
    }

    //print out a big line after time the loop goes through to make it easier to see
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;

    
  
  }
  
}



void goo(int &current, vector<room*> &rooms, char gotoo[]){
  //for the go function, make a character of the first character in gotoo, and pass it into the exitroom function of the room class. (see room.cpp for what the output of the function means)
  
  char where = gotoo[0];
  if(rooms[current]->exitRoom(gotoo) != -1){
    //if the output isnt 1, then set the currentroom(passed by reference) to the output
    current = rooms[current]->exitRoom(gotoo);

  } else {
    //otherwise say that it's not a valid exit
    cout << "that is not a valid exit." << endl;
  }
}



void get(int current, vector<room*> &rooms, char getting[], vector<char*> &inventory){
  //for the get function, if the item is found in the rooom(room->findItem), then remove the item from the current room and add it to the inventory. Then output that it has been added. 
  char* lookingfor = new char[20];
  strcpy(lookingfor, getting);
  if(rooms[current]->findItem(lookingfor)==true){
    rooms[current]->removeItem(getting);
    inventory.push_back(lookingfor);
    cout << lookingfor << " has been added to your inventory. " << endl;
  } else {
    //otherwise, output that the item either does not exist or is not in this room. 
    cout << "This item either does not exist or is not in this room. " << endl;
  }
}


void drop(int current, vector<room*> &rooms, char dropping[], vector<char*> &inventory){
  //for the drop function, go through the inventory and if the item is in the inventory, remove the item from the inventory and add the item to the room. Then output that the item has been dropped. 
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
  //if the function hasn't returned yet, then output that the item is not in the inventory. 
  cout << drop << " is not in your inventory. " << endl;
}

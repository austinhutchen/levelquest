#include "npc.h"
#include "player.h"
#include "backpack.h"
npc::npc()
{
  
  string food = "🍌";
  string bow = "🏹";
  string sword = "🗡";
  string armor = "🦾";
  position_x = 0;
  position_y = 0;
  character = "🤖";
  sinventory.push_back(food);
  spawn = false;
}

int npc::getlocationx()
{
  return position_x;
}
int npc::getlocationy()
{
  return position_y;
}
string npc::getchar(){
  return character;
}
// Implement player currency exchange here
int npc::sell(backpack backpack1)
{
  int choice;
  string item;
  cout << "What would you like to buy? I have food in stock." << endl;
  cout << "1)food,🍌" << endl;
  cout << "2)food,🍌" << endl;
  cout << "3)food,🍌" << endl;
  cout << "4)food,🍌" << endl;
  cout << "Enter your choice below: " << endl;
  cin >> choice;
  if(cin.fail()){
  cout << "Invalid input." << endl;
  return 0;
  }
  else{
switch (choice)
  {
  case 1:
    backpack1.additem("❤️");
    cout << "Thank you for buying. Come again! " << endl;
    return 1;
  case 2:
    backpack1.additem("❤️");
    cout << "Thank you for buying. Come again! " << endl;
    cout << backpack1.getinventory();
    return 1;
  case 3:
    backpack1.additem("❤️");
    cout << "Thank you for buying. Come again! " << endl;
    return 1;
  case 4:
    backpack1.additem("❤️");
    cout << "Thank you for buying. Come again! " << endl;
    return 1;
  default:
    cout << "I don't have that in inventory. Please choose from 1-4. " << endl;
    return -1;
  }
   return 0;
  }
}

void npc::spawnx(Player player1)
{
int x2 = rand() % player1.getlocationx();
  position_x = x2;
}

void npc::spawny(Player player1)
{
int y2 = rand() % player1.getlocationy();
  position_y = y2;
}

#include "backpack.h"
// 10 items allowed in backpack
backpack::backpack()
{
 numitems = 0;
}
int backpack::additem(string item)
{
 if (pinventory.size() < 10)
 {
  pinventory.push_back(item);
  cout << "Item successfully bought." << endl;
  numitems++;
  return 1;
 }
 if (pinventory.size() == 10)
 {
  cout << "Backpack is full." << endl;
  return 0;
 }
 else
 {
  cout << "vector error" << endl;
  return -1;
 }
}

int backpack::checkitems(Player p1)
{
 string choice;
 cout << "Would you like to use an item? y/n" << endl;
 cin >> choice;
 if(choice=="y"&&numitems>0){
 pinventory.pop_back();
 p1.gainhp(2);
 numitems--;
 return 1;
 }
 else{cout << "Item was not used." << endl;}
 return 0;
}

int backpack::heal(Player p1){
p1.gainhp(2);
return 1;
}

int backpack::getinventory(){
 return numitems;
}

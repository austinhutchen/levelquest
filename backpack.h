#ifndef backpack_h
#define backpack_h
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include "player.h"
using namespace std;
class backpack{
public:
backpack();
int checkitems(Player p1);
int additem(string);
int heal(Player p1);
int getinventory();
void additems(int idk){
 numitems+=idk;
for(int i=0;i<idk;i++){
pinventory.push_back("❤️");
}
}




private:
vector<string>pinventory;
int numitems;
};

#endif
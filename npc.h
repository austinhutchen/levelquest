#ifndef npc_h
#define npc_h
#include <iostream>
using namespace std;
#include <vector>
#include "backpack.h"
#include "player.h"
class npc{
 public:
npc();
void spawnx(Player);
void spawny(Player);
void setchar(string);
int getlocationx();
int getlocationy();
int sell(backpack);
string getchar();
private:

int position_x;
int position_y;
string character;
vector <string> sinventory;
bool spawn;


};



#endif
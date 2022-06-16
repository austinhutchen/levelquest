#ifndef battle_h
#define battle_h
#include "player.h"
#include "enemy.h"
#include "backpack.h"
#include "cstdlib"
#include <iostream>
using namespace std;
// main switch statement for battle options
class battle{
public:
battle();
int battlemenu(Player,Enemy,backpack);
int attack();
int defend();
int run();




private:
int playerturn;
int enemyturn;
bool flee;


};

#endif
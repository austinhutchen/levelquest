#ifndef enemy_h
#define enemy_h
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include "player.h"
using namespace std;
class Enemy {
 public:
Enemy();
Enemy(string,int);
void gethp();
int losehp();
int getlocationx();
int getlocationy();
void spawnx();
void spawny();
int getlevel();
string lowercase(string);
// below makes enemy move in random direction
void moverand();
// below makes enemy move in same direction as character 
void moveset(int);
void setchar(string);
string getchar();
int checkspawn();
void spawnTrue();
int sumhp();
int die();
int addEnemy(int,Enemy);
void setdifficulty(int diff);
int getdifficulty();
private:
int position_x;
int position_y;
vector <string>hp;
vector <string> level;
string character;
bool spawn;
bool alive;
int difficulty;
vector<Enemy>enemies;
};
#endif
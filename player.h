#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Player{
public:
Player();
Player(string);
// functions below
int getlocationx();
int getlocationy();
void setlocationx(int);
void setlocationy(int);
int growxp();
void right();
void left ();
void up();
void down();
void setchar(string);
string getchar();
void showhp();
int sumhp();
string lowercase(string);
void checkboundary();
void spawnTrue();
int checkspawn();
int getlevel();
int levelup();
int losehp();
void sethp(int);
int gainhp(int);
private:
// variables below
int position_x;
int position_y;
vector <string>hp;
vector<string>level;
string character;
bool spawn;
bool alive;
};
#endif


#ifndef map_h
#define map_h
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include "player.h"
#include "enemy.h"
#include "npc.h"
using namespace std;

class map{
public:
map();
map(string);
void outputarray(int,int,Player,Enemy,map);
void outputshop(int,int,Player,npc);
void setmap(string );
string getmap();
int getrows();
int getcols();
bool isempty(int row,int col,Player,Enemy);
int outputarr(string arr[],int size);
void setrows(int rows){
rowsize=rows;
};
void setcols(int columns){
colsize=columns;
};
private:
 string mainarr[10][15];
string _map;
 int rowsize;
 int colsize;
bool free;



};
#endif
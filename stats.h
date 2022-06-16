#ifndef stats_h
#define stats_h
#include "player.h"
#include <fstream>
#include "map.h"
#include "npc.h"
#include "player.h"
#include "enemy.h"
class stats{
 public:
stats();
int gethealth();
int save(string,string,int,int);
int score(int);
int setsave(string,int,int,int,int,int,int);
int getsave();
int getlevel();
int split(string,char,string arr[],int);
int clear();
int getinventory(){
return inventory;
}
string getplayer(){
 if(character!=""){
return character;
 }
 else{ return "0";}
}
int getrows(){
 return rows;
}
int getcols(){
return columns;
};
int getdifficulty(){
return difficulty;
}
private:
int health;
int level;
string character;
int inventory;
int rows;
int columns;
int difficulty;
};



#endif
#include "map.h"
map::map(){
 int rowsize = 10;
 int colsize = 15;
 _map="🗻";
}
map::map(string newmap){
_map=newmap;
rowsize=10;
 colsize=15;
}
// level corresponds to numbers of enemies on map
// implement npc spawning
// manipulate map spawn to avoid allowing enemy instance to spawn when dead
void map::outputarray(int x, int y,Player player1,Enemy enemy1,map map1)
{

 for (int i = 0; i < x; i++)
 {
  for (int p = 0; p < y; p++)
  {// for spawning map
   if (i != player1.getlocationx()&&i!=enemy1.getlocationx()||p != player1.getlocationy()&&p!=enemy1.getlocationy())
   {
    mainarr[i][p] = map1.getmap();
   }
   if(player1.checkspawn()==0){
    mainarr[player1.getlocationx()][player1.getlocationy()]=player1.getchar();
    player1.spawnTrue();
   }
   else if(enemy1.checkspawn()==0){
      mainarr[enemy1.getlocationx()][enemy1.getlocationy()]=enemy1.getchar();
  enemy1.spawnTrue();
   }
   // why is player double spawning? there is only one instance of the class with position details open
   else if (i == player1.getlocationx() && p == player1.getlocationy()&&player1.checkspawn()==1)
   {
    mainarr[i][p] = player1.getchar();
   }
   else if (i == enemy1.getlocationx() && p == enemy1.getlocationy()&&enemy1.checkspawn()==1)
   {
    mainarr[i][p] = enemy1.getchar();
   }
  }
 }
 for (int i = 0; i < x; i++)
 {
  for (int p = 0; p < y; p++)
  {
   cout << mainarr[i][p];
  }
  cout << endl;
 }
}
void map::setmap(string newmap){
_map=newmap;
}
string map::getmap(){
 return _map;
}
int map::getrows(){
 return rowsize;
}
int map::getcols(){
 return colsize;
}
// mostly for npc and enemy spawning, move over to that class later
bool map::isempty(int row,int col,Player p1,Enemy e1){

if(row==p1.getlocationx()&&col==p1.getlocationy()||row==e1.getlocationx()&&col==e1.getlocationy()){
return false;
}
else{return true;}
}

void map::outputshop(int x,int y,Player player1, npc npc1){
int playx=player1.getlocationx();
  int playy = player1.getlocationy();
  int npcx = npc1.getlocationx();
  int npcy = npc1.getlocationy();
 for (int i = 0; i < x; i++)
 {
  for (int p = 0; p < y; p++)
  {// for spawning map
   if (i != player1.getlocationx()&&i!=npc1.getlocationx()||p != player1.getlocationy()&&p!=npc1.getlocationy())
   {
    mainarr[i][p] = "∙";
   }
   if(player1.checkspawn()==0){
    mainarr[player1.getlocationx()][player1.getlocationy()]=player1.getchar();
    player1.spawnTrue();
   }
   else if (i == player1.getlocationx() && p == player1.getlocationy()&&player1.checkspawn()==1)
   {
    mainarr[i][p] = player1.getchar();
   }
   
      mainarr[npc1.getlocationx()][npc1.getlocationy()]=npc1.getchar();
  }
 }
 for (int i = 0; i < x; i++)
 {
  for (int p = 0; p < y; p++)
  {
   cout << mainarr[i][p];
  }
  cout << endl;
 }


}










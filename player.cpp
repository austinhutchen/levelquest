#include "player.h"
// main function declarations
Player::Player(string _character){
position_x=0;
 position_y=0;
 character=_character;
for(int i=0;i<3;i++){
hp.push_back("❤︎");
}
alive=true;
}
Player::Player(){
 position_x=0;
 position_y=0;
character="🤺";
for(int i=0;i<6;i++){
hp.push_back("❤︎");
}
alive=true;
}
string Player::lowercase(string input){
 
for(int x=0;x<input.size();x++){
if(input[x]>=65&&input[x]<=90){
int e=input[x]+32;
input[x]=e;
}
else{continue;}
}
// end of loop
return input;
}

int Player::getlocationx(){
return position_x;
}
int Player::getlocationy(){
return position_y;
}
void Player::setlocationx(int posx){
position_x=posx;
}
void Player::setlocationy(int posy){
position_y=posy;
}
void Player::right(){
  // numrows is 10
if(position_y!=14){
position_y++;
}}
void Player::left(){
if(position_y!=0){
  position_y--;
}}
void Player::up(){
if(position_x!=0){
  position_x--;
}}
// numcols is 15
void Player::down(){
if(position_x!=9){
  position_x++;
}}
void Player::setchar(string newchar){
character=newchar;
}
string Player::getchar(){
 return character;
}    
void Player::showhp(){
for(int i=0;i<hp.size();i++){
cout << hp[i];
}
cout << endl;
}
void Player::spawnTrue(){
spawn=true;
}
int Player::checkspawn(){
if(spawn==true){
return 1;
}
else {return 0;}
}
int Player::getlevel(){
int lvl =0;
for(int i=0;i<level.size();i++){
if(level[i]=="⭐️"){
lvl++;
}
}
return lvl;
}
int Player::sumhp(){
 int health =0;
for(int i=0;i<hp.size();i++){
if(hp[i]=="❤︎"){
health++;
}
}
return health;
}
int Player::levelup(){
level.push_back("⭐️");
cout << "Your character's level is : ";
for(int i=0;i<level.size();i++){
cout << level[i];
}
cout << endl;
return 1;
}
int Player::losehp(){
  if(hp.size()>0){
hp.pop_back();
for(int i=0;i<hp.size();i++){
cout << hp[i];
}
cout << endl; 
cout << "You have lost hp!" << endl;
return 1;
  }
  else{
    cout << "You died. " << endl;
    return 0;}
}
int Player::gainhp(int amount){

 for(int i=0;i<amount;i++){
hp.push_back("❤︎");
 }
for(int i=0;i<hp.size();i++){
cout << hp[i];
}
cout << endl; 
cout << "You have gained hp!" << endl;
return 1;
  }




void Player::sethp(int _hp){
for(int i=0;i<_hp;i++){
hp.push_back("❤︎");
}
}

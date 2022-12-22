#include "enemy.h"
Enemy::Enemy(string _enemy,int health)
{
  position_x = 0;
  position_y = 0;
  character = _enemy;
  for (int i = 0; i < health; i++)
  {
    hp.push_back("❤︎");
  }
  alive=true;
  difficulty=1;
}
Enemy::Enemy()
{
  position_x = 0;
  position_y = 0;
  character = "👹";
  for (int i = 0; i < 3; i++)
  {
    hp.push_back("❤︎");
  }
  alive = true;
}
void Enemy::spawnx()
{
  int x2 = rand() % 10;
  position_x = x2;
}
void Enemy::spawny()
{
  int y2 = rand() % 15;
  position_y = y2;
}
int Enemy::getlocationx()
{
  return position_x;
}
int Enemy::getlocationy()
{
  return position_y;
}
string Enemy::lowercase(string input)
{

  for (int x = 0; x < input.size(); x++)
  {
    if (input[x] >= 65 && input[x] <= 90)
    {
      int e = input[x] + 32;
      input[x] = e;
    }
    else
    {
      continue;
    }
  }
  // end of loop
  return input;
}
void Enemy::moverand()
{
  // instead of relying on rand values, use djikstras for shortest path to enemy along given vertices in array bounds
  int move = rand() % 2;
  // two cases reflect choices to move forwards or backwards in either the x or y direction
  switch (move)
  {
  case 0:
  {
    int randnum = rand() % 3;
    if (randnum == 1)
    {
      if (position_x != 0)
      {
        position_x--;
      }
      else if (position_x == 0 && position_y == 14)
      {
        position_y--;
      }
      else if (position_x == 0 && position_y == 0)
      {
        position_y++;
      }
    }
    if (randnum == 2)
    {
      // random choice is to move 
      if (position_x != 9)
      {
        position_x++;
      }
      else if (position_x == 9 && position_y == 14)
      {
        position_y--;
      }
      else if (position_x == 9 && position_y == 0)
      {
        position_y++;
      }
    }
    if (randnum == 0)
    {
      // do nothing if the random choice is to not move
    }
  }
  break;
  case 1:
    int y2 = rand() % 3;
    if (y2 == 1)
    {
      if (position_y != 0)
      {
        position_y--;
      }
      else if (position_y == 0 && position_x == 14)
      {
        position_x--;
      }
      else if (position_x == 0 && position_y == 0)
      {
        position_x++;
      }
    }
    if (y2 == 2)
    {
      if (position_y != 14)
      {
        position_y++;
      }
      // fix below
      else if (position_y == 14 && position_x == 0)
      {
        position_x++;
      }
      else if (position_y == 14 && position_x == 9)
      {
        position_x--;
      }
      if (y2 == 0)
      {
      }
    }
    break;
  }
}
void Enemy::gethp()
{
  for (int i = 0; i < hp.size(); i++)
  {
    cout << hp[i];
  }
  cout << endl;
}
void Enemy::spawnTrue()
{
  spawn = true;
}
int Enemy::checkspawn()
{
  if (spawn == true)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
string Enemy::getchar()
{
  return character;
}
int Enemy::losehp()
{
  if (hp.size() > 0)
  {
    hp.pop_back();
    cout << "Enemy has lost hp!" << endl;
    for (int i = 0; i < hp.size(); i++)
    {
      cout << hp[i];
    }
    cout << endl;
    return 1;
  }
  else
  {
    cout << "Enemy has died. " << endl;
    return 0;
  }
}
int Enemy::sumhp()
{
  int health = 0;
  for (int i = 0; i < hp.size(); i++)
  {
    if (hp[i] == "❤︎")
    {
      health++;
    }
    else
    {
      continue;
    }
  }
  return health;
}
int Enemy::getlevel()
{
  int lvl = 0;
  for (int i = 0; i < level.size(); i++)
  {
    if (level[i] == "⭐️")
    {
      lvl++;
    }
  }
  return lvl;
}
// manipulate map spawn to avoid allowing enemy instance to spawn when dead
int Enemy::die()
{
  if (alive == true)
  {
    alive = false;
    return 1;
  }
  else
  {
    cout << "Error. Enemy is already in a dead state." << endl;
    return -1;
  }
}
int Enemy::addEnemy(int level, Enemy enemyt)
{
  for (int i = 0; i < level; i++)
  {
    enemies.push_back(enemyt);
  }
  return 1;
}
void Enemy::setchar(string newchar){

character=newchar;
}
void Enemy::setdifficulty(int diff){
  difficulty=diff;
}
int Enemy::getdifficulty(){
return difficulty;
}
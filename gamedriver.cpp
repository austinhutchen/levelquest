#include "player.h"
#include "enemy.h"
#include "npc.h"
#include "map.h"
#include "backpack.h"
#include "battle.h"
#include "stats.h"
#include <fstream>
using namespace std;
int main()
{
  srand(time(NULL));
  Player player1 = Player();
  const string characters[4] = {"🥋", "🤺", "😀", "🧿"};
  int rowchoice;
  int colchoice;
  int level = 0;
  int exit = 0;
  int display = 0;
  int option;
  string _map;
  int main_choice;
  string move_choice;
  battle battle1 =  battle();
  backpack backpack1 = backpack();
  npc npc1 = npc();
  stats save = stats();
 
  vector<Enemy> enemies;
  vector<map> maps;
  string guy;
  int hp;
  save.getsave();
if(save.getplayer()!="0"){
player1.setchar(save.getplayer());
}
else{player1.setchar("😀");}
  backpack1.additems(1);
  for (int i = 0; i < 12; i++)
  {
    switch (i)
    {
    case 0:
      _map = "⛳️";
      break;
    case 1:
      _map = "⛳️";
      break;
    case 2:
      _map = "🛕";
      break;
    case 3:
      _map = "🗻";
      break;
    case 4:
      _map = "🌲";
      break;
    case 5:
      _map = "🌋";
      break;
    case 6:
      _map = "💠";
      break;
    case 7:
      _map = "🌏";
      break;
    case 8:
      _map = "🛸";
      break;
    case 9:
      _map = "🪐";
      break;
    case 10:
      _map = "▪︎";
      break;
    // NPC SHOP ONly
    case 11:
      _map = "·";
      break;
    }
    maps.push_back(map(_map));
  }
  for (int i = 0; i < 10; i++)
  {

    switch (i)
    {
    case 0:
      guy = "🦂";
      hp = 3;
      break;
    case 1:
      guy = "🦂";
      hp = 5;
      break;
    case 2:
      guy = "🐊";
      hp = 6;
      break;
    case 3:
      guy = "🦍";
      hp = 8;
      break;
    case 4:
      guy = "🧛🏽";
      hp = 9;
      break;
    case 5:
      guy = "🧟";
      hp = 10;
      break;
    case 6:
      guy = "🐲";
      hp = 11;
      break;
    case 7:
      guy = "👾";
      hp = 13;
      break;
    case 8:
      guy = "🧌";
      hp = 15;
      break;
    case 9:
      guy = "👹";
      hp = 20;
      break;
    }
    enemies.push_back(Enemy(guy, hp));
  }

  cout << "----->MAIN MENU<-----" << endl;
  cout << "1: Load save" << endl;
  cout << "2. Start" << endl;
  cout << "3: Choose character" << endl;
  cout << "4: Item shop " << endl;
  cout << "5: Change map size " << endl;
  cout << "6. Set difficulty " << endl;
  cout << "7: Quit " << endl;
  cin >> main_choice;
  switch (main_choice)
  {
  case 1:
  {
    int s = save.getsave();
    if (s == 1)
    {
      player1.sethp(save.gethealth());
      level = save.getlevel();
      backpack1.additems(save.getinventory());

      for(int i=0;i<10;i++){
       enemies[i].setdifficulty(save.getdifficulty());
      }
      for (int i = 0; i < 12; i++)
      {
        maps[i].setrows(save.getrows());
        maps[i].setcols(save.getcols());
      }
      cout << "Save successfully loaded. Continue on your journey." << endl;
    }
    else
    {
      cout << "Save is corrupt." << endl;
      cout << "No save was loaded. Your journey begins anew! " << endl;
    }
  }
  case 2:
  {
    // main loop
    while (exit != 1)
    {
      // below is good, can stay the same
      if (level == 0)
      {
        // enemies array here
        cout << "TUTORIAL LEVEL" << endl;
        cout << "Your map is a cartesian plane with 10 rows and 15 columns." << endl;
        cout << "Enter your initial row location:" << endl;
        cin >> rowchoice;
        if (rowchoice - 1 > maps[level].getrows() || rowchoice < 0 || cin.fail())
        {
          cout << "Invalid input. " << endl;
          return main();
        }
        cout << "Enter your initial column location:" << endl;
        cin >> colchoice;
        if (colchoice - 1 > maps[level].getcols() || colchoice < 0 || cin.fail())
        {
          cout << "Invalid input. " << endl;
          return main();
        }
        player1.setlocationx(rowchoice - 1);
        player1.setlocationy(colchoice - 1);
        enemies[level].spawnx();
        enemies[level].spawny();
        maps[level].outputarray(maps[level].getrows(), maps[level].getcols(), player1, enemies[level], maps[level]);
        cout << "Enemy has spawned!" << endl;
        cout << "------->LEVEL 1<-------" << endl;
        cout << "Your current health is: " << endl;
        player1.showhp();
        cout << "Your enemies health is: " << endl;
        enemies[level].gethp();
        level++;
      }
      if (level > 0 && level < 9) // implement final level subtext and game finish menu for when level==9
      {
        // map change with enemies
        if (display == 1)
        {
          cout << "-->LEVEL " << level << "<--" << endl;
          cout << "Would you like to move up, down, left, or right? Use WASD to navigate, and type none to stay still." << endl;
          cout << "This message only displays once." << endl;
          display++;
        }
        // player position not changing with new enemy array
        cin >> move_choice;
        if (player1.lowercase(move_choice) == "w")
        {
          player1.up();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "s")
        {
          player1.down();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "a")
        {
          player1.left();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "d")
        {
          player1.right();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "none")
        {
          enemies[level].moverand();
        }

        if (player1.lowercase(move_choice) == "save")
        {
          int s = save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
          if (s == 1)
          {
            cout << "Save was succesful. " << endl;
          }
          else
          {
            cout << "Save is corrupted." << endl;
          }
        }
        if (player1.lowercase(move_choice) == "quit")
        {
          cout << "Thanks for playing!" << endl;
          int s = save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
          if (s == 1)
          {
            cout << "Autosave was succesful. " << endl;
          }
          else
          {
            cout << "Save is corrupted." << endl;
          }
          return 0;
        }
        maps[level].outputarray(maps[level].getrows(), maps[level].getcols(), player1, enemies[level], maps[level]);
        cout << "Your current health is: " << endl;
        player1.showhp();
        cout << "Your enemies health is: " << endl;
        enemies[level].gethp();
        // work on below and battle menu
        if (enemies[level].getlocationx() == player1.getlocationx() && enemies[level].getlocationy() == player1.getlocationy())
        {
          int b = battle1.battlemenu(player1, enemies[level], backpack1);
          if (b == 0)
          {
            cout << "Game over! You died!" << endl;
            cout << "Your stats were not saved." << endl;
            save.clear();
            return 0;
          }
          if (b == 1)
          {
            cout << enemies[level].getchar() << " says : NOOOOOO" << endl;
            
            cout << "You won! Your score was updated. Continue on your Journey." << endl;
            display = 0;
            enemies[level].die();
            level++;
            player1.levelup();
          }
          if (b == 2)
          {
            cout << "You fled the battle. Your health + levels have not changed. Continue on your Journey. " << endl;
            player1.showhp();
          }
        }
      }
      if (level == 9)
      {
        int end = 0;
        cout << "-------FINAL LEVEL------" << endl;
        cout << "The final boss appears. " << endl;
        cout << enemies[level].getchar();
        cout << "Move with WASD." << endl;
        cin >> move_choice;
        if (player1.lowercase(move_choice) == "w")
        {
          player1.up();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "s")
        {
          player1.down();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "a")
        {
          player1.left();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "d")
        {
          player1.right();
          enemies[level].moverand();
        }
        if (player1.lowercase(move_choice) == "none")
        {
          enemies[level].moverand();
        }
        maps[level].outputarray(maps[level].getrows(), maps[level].getcols(), player1, enemies[level], maps[level]);
        if (enemies[level].getlocationx() == player1.getlocationx() && enemies[level].getlocationy() == player1.getlocationy())
        {
          int b = battle1.battlemenu(player1, enemies[level], backpack1);
          if (b == 0)
          {
            cout << "Game over! You died!" << endl;
            cout << "Your stats were not saved." << endl;
            save.clear();
            return 0;
          }
          if (b == 1)
          {
            cout << enemies[level].getchar() << " says : NOOOOOO" << endl;
            cout << "You won! Your score was updated. Game complete!" << endl;
            cout << "CREDITS" << endl;
            cout << "Game by : Austin" << endl;
            cout << "Design by : Austin" << endl;
            cout << "Graphics by : Austin" << endl;
            cout << "Dialogue by : Austin" << endl;
            cout << "Conclusion by : Austin" << endl;
            cout << "Coolness by : Austin" << endl;
            cout << "Genius level design by : Austin" << endl;
            cout << "Thanks for playing!" << endl;
            return 0;
            end = 1;
            enemies[level].die();
            player1.levelup();
          }
          if (b == 2)
          {
            cout << "You fled the battle. Your health + levels have not changed. You can continue to wander." << endl;
            player1.showhp();
          }
        }
      }
    }
    break;
  }

  case 3:
  {
    int i = -1;
    string inputchoice;
    string choicearr[4] = {"🔹", "🔹", "🔹", "🔹"};
    cout << "You can choose your character from the list of options displayed below. Choose wisely." << endl;
    for (int i = 0; i < 4; i++)
    {
      cout << characters[i];
    }
    for (int i = 0; i < 4; i++)
    {
      cout << characters[i];
    }
    cout << "Use A and D to choose, type yes when you've chosen your character." << endl;
    while (inputchoice != "yes")
    {
      cin >> inputchoice;
      if (player1.lowercase(inputchoice) == "d")
      {
        for (int n = 0; n < 4; n++)
        {
          cout << characters[n];
        }
        cout << endl;
        if (i != 3)
        {
          i += 1;
        }
        for (int k = 0; k < 4; k++)
        {
          if (k == i)
          {
            cout << "⬆︎";
          }
          else
          {
            cout << choicearr[k];
          }
        }
        cout << endl;
      }
      else if (player1.lowercase(inputchoice) == "a")
      {
        for (int n = 0; n < 4; n++)
        {
          cout << characters[n];
        }
        cout << endl;
        if (i != 0)
        {
          i -= 1;
        }
        for (int k = 0; k < 4; k++)
        {
          if (k == i)
          {
            cout << "⬆︎";
          }
          else
          {
            cout << choicearr[k];
          }
        }
        cout << endl;
      }
    }

    if (player1.lowercase(inputchoice) == "yes")
    {
      player1.setchar(characters[i]);
    }
    cout << "Your character has succesfully been changed. " << endl;
    cout << player1.getchar() << endl;
    int s = save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
    if (s == 1)
    {
      cout << "Save was succesful." << endl;
      return main();
    }
    else
    {
      cout << "Save error." << endl;
      return 0;
    }
    // job of the save class will be to ensure characters after this point do not change
    break;
  }
    // case 3->6 here
  case 4:
  {
    int quit = 0;
    cout << "=====THE SHOP=====" << endl;
    cout << npc1.getchar() << " Welcome to the shop. Walk around and browse my shop, or buy from me when you're ready. " << endl;
    player1.setlocationx(9);
    player1.setlocationy(14);
    // below calls a rand function
    npc1.spawnx(player1);
    npc1.spawny(player1);
    // output map here
    while (quit != 1)
    {
      maps[11].outputshop(10, 15, player1, npc1);
      cout << "Use WASD to navigate, and type none to stay still." << endl;
      cin >> move_choice;
      if (player1.lowercase(move_choice) == "w")
      {
        player1.up();
      }
      if (player1.lowercase(move_choice) == "s")
      {
        player1.down();
      }
      if (player1.lowercase(move_choice) == "a")
      {
        player1.left();
      }
      if (player1.lowercase(move_choice) == "d")
      {
        player1.right();
      }
      if (player1.lowercase(move_choice) == "none")
      {
      }
      if (player1.lowercase(move_choice) == "quit")
      {
        // implement inventory save here
        int s = save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
        if (s == 1)
        {
          cout << "Autosave was succesful. " << endl;
        }
        else
        {
          cout << "Save is corrupted." << endl;
        }
        return main();
      }
      else
      {
        cout << "Invalid input." << endl;
      }
      if (player1.getlocationx() == npc1.getlocationx() && player1.getlocationy() == npc1.getlocationy())
      {
        // work on this function here
        int n = npc1.sell(backpack1);
        save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
        cout << "Your inventory has been updated." << endl;
      }
    }

    break;
  }
    // change map size below
  case 5:
  {
    int numrows;
    int numcols;
    cout << "->MAP SETTINGS<-" << endl;
    cout << "You can change your map size here." << endl;
    cout << "Enter your choice for the number of map rows below." << endl;
    cin >> numrows;
    if (cin.fail())
    {
      cout << "Invalid input." << endl;
      return main();
    }
    for (int i = 0; i < 12; i++)
    {
      maps[i].setrows(numrows);
    }
    cout << "Enter your choice for the number of map columns below." << endl;
    cin >> numcols;
    if (cin.fail())
    {
      cout << "Invalid input." << endl;
      return main();
    }
    for (int i = 0; i < 12; i++)
    {
      maps[i].setcols(numrows);
    }
    cout << "Map has been adjusted." << endl;
    save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
    return main();
  }
  break;

  case 6:
  {
    // set difficulty number denotes probability of hitting enemy
    int choice = 0;
    cout << "You can adjust the difficulty of the enemies of the game here. " << endl;
    cout << "What difficulty level do you choose?" << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cin >> choice;
    if (choice == 1)
    {
      for (int i = 0; i < 10; i++)
      {
        enemies[i].setdifficulty(0);
      }
      cout << "Difficulty adjusted." << endl;
      save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
      return main();
    }
    if (choice == 2)
    {
      for (int i = 0; i < 10; i++)
      {
        enemies[i].setdifficulty(6);
      }
      cout << "Difficulty adjusted." << endl;
      save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
      return main();
    }
    if (choice == 3)
    {
      for (int i = 0; i < 10; i++)
      {
        enemies[i].setdifficulty(10);
      }
      cout << "Difficulty adjusted." << endl;
      save.setsave(player1.getchar(), level, player1.sumhp(), backpack1.getinventory(), maps[0].getrows(), maps[0].getcols(), enemies[0].getdifficulty());
      return main();
    }
  }
  case 7:
  {
    cout << "-Thanks for playing!-" << endl;
    // save scores
    return 0;
  }

  default:
  {
    cout << "Invalid input. " << endl;
    return main();
  }
    // end of switch
  }
}

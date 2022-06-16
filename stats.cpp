#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "stats.h"
using namespace std;

int stats::split(string inputstring, char seperator, string arr[], int size)
{
  // number of split strings stored in count
  int count = 0;
  int i = 0;
  int start = 0;
  int end = 0;
  // input validation
  if (inputstring.empty())
  {
    return 0;
  }

  while (end < inputstring.size())
  {
    if (inputstring[end] == seperator)
    {
      int length = end - start;
      // if length is 0, use -1 (error is here)
      if (i == length)
      {
        return -1;
      }
      arr[i++] = inputstring.substr(start, length);
      // move up 1 to avoid delimiter
      end++;
      start = end;
    }
    else
    {
      end++;
    }
  }
  int length = end - start;
  // error checking for array size greater than the required
  if (i >= size)
  {
    return -1;
  }
  arr[i++] = inputstring.substr(start, length);
  return i;
}

stats::stats()
{
  int defeated = 0;
  int health = 0;
  int level = 0;
  double pscore = 0;
  string character = "";
  difficulty=0;
  rows=0;
  columns=0;
}

int stats::setsave(string character, int level, int playerhealth, int inventory, int rows, int columns, int difficulty)
{
  ofstream file1("saves.txt");
  if (file1.fail())
  {
    cout << "File could not be opened. " << endl;
    return -1;
  }
  file1<<character<<", "<< level <<" , "<< playerhealth <<" ,"<<inventory <<" ,"<<rows <<" ,"<<columns <<" ,"<<difficulty << endl;
  file1.close();
  return 1;
}

int stats::getsave()
{
  string arr[7];
  ifstream fin;
  string line;
  fin.open("saves.txt");
  if (fin.fail())
  {
    cout << "File could not be opened. " << endl;
    return -1;
  }
  fin.seekg(0, ios::beg);
  while (getline(fin, line))
  {
    int s=split(line,',', arr,7);
    // error testing above
    character = arr[0];
    level = stoi(arr[1]);
    health = stoi(arr[2]);
    inventory = stoi(arr[3]);
    rows = stoi(arr[4]);
    columns = stoi(arr[5]);
    difficulty = stoi(arr[6]);
    fin.close();
    return 1;
  }
  fin.close();
  return -1;
}

int stats::getlevel()
{
  return level;
}

int stats::gethealth()
{
  return health;
}

int stats::clear()
{
  ofstream fout("saves.txt");
  if (fout.fail())
  {
    cout << "File could not be opened. " << endl;
    return -1;
  }
  else
  {
    return 1;
  }
}

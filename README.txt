HOW TO COMPILE AND RUN


use the below to compile;

g++ player.cpp enemy.cpp gamedriver.cpp map.cpp battle.cpp stats.cpp npc.cpp backpack.cpp
and execute using ./a.out.


DEPENDENCIES
player.h enemy.h gamedriver.h map.h battle.h stats.h npc.h backpack.h AND SAVES.TXT must remain in the same folder for proper compilation. 
DO NOT modify the saves.txt file. This will corrupt saves.

SUBMISSION INFORMATION
CSCI1300 Spring 2022 Project 3
Author: Austin Hutchen
Recitation: 205 - Alex Ray
Date: April 21, 2022

ABOUT THIS PROJECT
The objective of this game is to beat all nine levels. Player health is set at 6, items can be used to heal, and enemy difficulty can be scaled accordingly, based on differing rand values for their actions during combat. Autosave is built-in using the saves.txt file.
USE WASD TO MOVE
TYPE ATTACK, DEFEND, RUN, or HEAL in combat to use your options.

WAYS TO IMPROVE THIS GAME:
Use multithreading to do something like output map while waiting for other input
Implement items system
Make the map output faster, instead of two for loops with lots of if conditions
Use proper memory allocation practices when declaring and disposing of unused variables
use struct pointers for players and enemies to make passing data into functions easier
pass-by-reference aas often as possible




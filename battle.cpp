#include "battle.h"

battle::battle()
{
    playerturn = 0;
    enemyturn = 0;
    flee = false;
}

// battle menu
int battle::battlemenu(Player player1, Enemy enemy1,backpack backpack1)
{
    bool attack = false;
    bool defend = false;
    string battlechoice;
    int mainchoice;
    cout << "-------- BATTLE STARTED! --------" << endl;
    cout << enemy1.getchar() << "Enemy says: You stand no chance. " << endl;

    while (player1.sumhp() > 0 && enemy1.sumhp() > 0 && flee != true)
    {
        bool attack = false;
        bool defend = false;
        int y = rand() % 10;
        int choice = rand() % 2;
        int k = rand() % 5;
        int r = rand() % 2;
        cout << "Would you like to attack, defend, or attempt to run? Enter your choice below. " << endl;
        cout << "USE A for ATTACK, D for DEFEND, or F to RUN." << endl;
        cin >> battlechoice;
        if (player1.lowercase(battlechoice) == "a")
        {
            mainchoice = 1;
        }
        else if (player1.lowercase(battlechoice) == "d")
        {
            mainchoice = 2;
        }
        else if (player1.lowercase(battlechoice) == "F")
        {
            mainchoice = 3;
        }
        else if(player1.lowercase(battlechoice)=="heal"){
        int b= backpack1.checkitems(player1);
        if(b==0){
        cout << "Unsuccessful heal." << endl;
        }
        if(b==1){
        cout << "Successful heal." << endl;
        }
        }
        // main switch, work on below
        switch (mainchoice)
        {
        case 1:
            cout << "You swung your weapon at the enemy! 🗡" << endl;
            cout << enemy1.getchar()<<endl;
            // implement differences in difficulty hitting enemy depending on level
            attack = true;
            break;
        case 2:
            cout << "You entered the defensive stance.🛡 " << endl;
            cout << ".........." << endl;
            defend = true;
            break;
        case 3:
            if (y == 5 || y == 6 || y == 7)
            {
                flee = true;
            }
            else
            {
                cout << "You cannot flee. The enemy is too strong." << endl;
                continue;
            }
            break;
        default:
            cout << "Invalid input. " << endl;
            // fix here
            break;
        }
        // change rand
        switch (choice)
        {
            cout << "Enemies turn. " << endl;
        case 0:
            cout << "Enemy attacks!🗡" << endl;

            if (r == 0 && defend == true)
            {
                cout << "You blocked the attack!" << endl;
            }
            else if (r == 1 || defend == false)
            {
                cout << "The enemy hit you." << endl;
                player1.losehp();
            }
            if (attack == true)
            {
                int a=rand()%enemy1.getdifficulty();
                if(a<3){
                cout << "You damaged the enemy." << endl;
                enemy1.losehp();
                }
                else{
                cout << "Your enemy dodged the attack." << endl;
                }
            }
            break;
        case 1:
            cout << "Enemy chooses to defend.🛡" << endl;
            if (k == 0||k==2||k==3||k==4 || attack == false)
            {
                cout << "You did not hit the enemy." << endl;
            }
            if (k == 1 && attack == true)
            {
                cout << "You managed to hit the enemy through their defenses." << endl;
                enemy1.losehp();
            }
            break;
        }
    }
    if (player1.sumhp() == 0)
    {
        return 0;
    }
    else if (enemy1.sumhp() == 0)
    {
        enemy1.die();
        return 1;
    }
    else if (flee == true)
    {
        cout << "You have fled the battle. " << endl;
         flee = false;
        return 2;
       
    }
    else
    {
        cout << "function error. check code." << endl;
        return -1;
    }
}
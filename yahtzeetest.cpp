#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

#include "Yahtzee.h"

int main(){
    bool computer;
    int numPlayers;
    char cpu;
    cout << "How many players? ";
    cin >> numPlayers;
    cout << "Computer player? Y/N ";
    cin >> cpu;
    if (cpu == 'N' || cpu == 'n'){
        computer = false;
    }else{
        computer = true;
    }
    playYahtzee(numPlayers, computer);
}
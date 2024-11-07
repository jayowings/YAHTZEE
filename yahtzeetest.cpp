#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

#include "Yahtzee.h"

int gamesWon=0;
char again;

int main(){
    while(true){
        YahtzeeSetUp(gamesWon);
        cout << "Play again? Y/N\n";
        cin >> again;
        if(again != 'Y'){
            break;
        }
    }
    return 0;
}
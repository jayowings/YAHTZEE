#include <iostream>
#include <cctype>
#include "Yahtzee.h"

using namespace std;

int main(){
    int numplayers;
    cout << "How many players?";
    cin >> numplayers;
    bool comp;
    cout << "Add computer player? Y/N";
    char c;
    cin >> c;
    switch (c){
        case 'Y':{
            comp = true;
            break;
        }default:{
            comp = false;
        }
    }
    playYahtzee(numplayers, comp);
}
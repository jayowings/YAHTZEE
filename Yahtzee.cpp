#include <iostream>
using namespace std;
#include "Yahtzee.h"
#include "Dice.h"

void YahtzeePlayer::Pturn(){ //roll logic and save dice logic, call other functions
    cout << name << ", your turn!" << endl;
    Dice d1, d2, d3, d4, d5;
    int i = 0;
    for(i; i < 3; i++){//three tries per dice
        if(d1.save != true){//if the dice has not been saved, roll it
            d1.roll();
        }
        if(d2.save != true){
            d2.roll();
        }
        if(d3.save != true){
            d3.roll();
        }
        if(d4.save != true){
            d4.roll();
        }
        if(d5.save != true){
            d5.roll();
        }
        char s1, s2, s3, s4, s5;
        cout << d1.value << " " << d2.value << " " << d3.value << " " << d4.value << " " << d5.value << endl;
        if(i == 2){ //There is no reason to save dice the third time
            break;
        }else{
            cout << "Push Y/N for each dice to save it (No spaces, e.g. YNYYN)" << endl;//Dice must be saved every time
            cin >> s1, s2, s3, s4, s5;
            if((char) toupper(s1) == 'Y'){
                d1.save = true;
            }else{
                d1.save = false;
            }if((char) toupper(s2) == 'Y'){
                d2.save = true;
            }else{
                d2.save = false;
            }if((char) toupper(s3) == 'Y'){
                d3.save = true;
            }else{
                d3.save = false;
            }if((char) toupper(s4) == 'Y'){
                d4.save = true;
            }else{
                d4.save = false;
            }if((char) toupper(s5) == 'Y'){
                d5.save = true;
            }else{
                d5.save = false;
            }
            if((char) toupper(s1) == 'Y' && (char) toupper(s2) == 'Y' && (char) toupper(s3) == 'Y' && (char) toupper(s4) == 'Y' && (char) toupper(s5) == 'Y'){
                break; //if all dice are saved, take these dice to decide score
            }
        }
    }
    chooseScore(d1.value, d2.value, d3.value, d4.value, d5.value);
    if(turnorder->computer){//Computer turn will have its own logic
        turnorder->Cturn();
    }else if(!endPlayer){
        turnorder->Pturn();//each player will take their turn in order, 
    }
};

void YahtzeePlayer::endGame(){
    upperTotal = ones + twos + threes + fours + fives + sixes;
    if(upperTotal >= 63){
        upperTotal += UPPERBONUS;
    }
    lowerTotal = threeOfAKind + fourOfAKind + fullHouse + smallStaight + largeStraight + yahtzee + yahtzeeBonus + Chance;
    total = upperTotal + lowerTotal;
    cout << setw(16) << left << name << endl;
    cout << "Ones:_____________" << ones << endl;
    cout << "Twos:____________" << setw(2) << left << setfill('_') << twos << endl;
    cout << "Threes:__________" << setw(2) << left << setfill('_') << threes << endl;
    cout << "Fours:___________" << setw(2) << left << setfill('_') << fours << endl;
    cout << "Fives:___________" << setw(2) << left << setfill('_') << fives << endl;
    cout << "Sixes:___________" << setw(2) << left << setfill('_') << sixes << endl;
    if(upperTotal > 63){
        cout << "BONUS!!" << endl;
    }
    cout << "Upper Total:____" << setw(3) << left << setfill('_') << upperTotal << endl;
    cout << "Three of a Kind:_" << setw(2) << left << setfill('_') << threeOfAKind << endl;
    cout << "Four of a Kind:__" << setw(2) << left << setfill('_') << fourOfAKind << endl;
    cout << "Full House:______" << setw(2) << left << setfill('_') << fullHouse << endl;
    cout << "SM Straight:_____" << setw(2) << left << setfill('_') << smallStaight << endl;
    cout << "LG Straight:_____" << setw(2) << left << setfill('_') << largeStraight << endl;
    cout << "Yahtzee:_________" << setw(2) << left << setfill('_') << yahtzee << endl;
    if(yahtzee != 0){
        cout << "Yahtzee Bonus:___" << setw(3) << left << setfill('_') << yahtzeeBonus << endl;
    }
    cout << "Chance:__________" << setw(2) << left << setfill('_') << Chance << endl;
    cout << "Lower Total:____" << setw(3) << left << setfill('_') << lowerTotal << endl;
    cout << "Total:_________" << setw(4) << left << setfill('_') << total << endl;
}; //calculating totals

void YahtzeePlayer::chooseScore(int d1, int d2, int d3, int d4, int d5){
    //sort dice in ascending order with temp variables. check sm straight or lg straight (if available, set and end turn)
    int temp;
    char takePoints;
    bool TP = false, FP = false, FHP = false, SP = false, LP = false, YP = false;
    int total = (d1 + d2 + d3 + d4 + d5);
    bool endTurn;
    while(d1 > d2 || d2 > d3 || d3 > d4 || d4 > d5){
        if(d1 > d2){
            temp = d1;
            d1 = d2;
            d2 = temp;
        }
        if(d2 > d3){
            temp = d2;
            d2 = d3;
            d3 = temp;
        }
        if(d3 > d4){
            temp = d3;
            d3 = d4;
            d4 = temp;
        }
        if(d4 > d5){
            temp = d4;
            d4 = d5;
            d5 = temp;
        }
    }
    if(d2 + 1 == d3 && d3 + 1 == d4 && (d1 + 1 == d2 || d4 + 1 == d5) && (largeStraight == -1 || smallStraight == -1)){
        if(d1 + 1 == d2 && d4 + 1 == d5 && largeStraight == -1){
            cout << "Large Straight! 40 points! Y/N";
            cin >> takePoints;
            if(takePoints != 'N' || takePoints != 'n'){
                largeStraight = LGSTRAIGHT;
                endTurn = true;
            }else{
                LP = true;
                if(smallStraight == -1) {
                    SP = true;
                }
            }
            //LG Straight
        }else if(smallStraight == -1){
            cout << "Small Straight! 30 points! Y/N";
            cin >> takePoints;
            if(takePoints != 'N' || takePoints != 'n'){
                smallStraight = SMSTRAIGHT;
                endTurn = true;
            }else{
                LP = false;
                SP = true;
            }
            //SM Straight
        }
    }
    //check number of same type dice
    if(d1 == d2){
        if(d2 == d3){
            if(d3 == d4){
                if(d4 == d5){
                    //if all dice are the same and Yahtzee has not been set to 0 or 50, yahtzee = 50. End turn
                        // if all dice are the same and Yahtzee is 50, add Yahtzee bonus, but don't end turn
                    cout << "YAHTZEE!!"
                    if(yahtzee == -1){
                        cout << "50 points! Y/N";
                        cin >> takePoints;
                        if(takePoints != 'N' || takePoints != 'n'){
                            yahtzee = YAHTZEE;
                            endTurn = true;
                        }else{
                            YP = true;
                        }
                    }
                    else if(yahtzee == 50){
                        yahtzeeBonus += BONUS;
                        cout << "BONUS 100 POINTS!!" << endl;
                    }else if(yahtzee == 0){
                        cout << ":.-( so sad." << endl;
                    }
                }
                if(!endTurn){
                    //if four dice are the same, display and offer four of a kind if available (end turn if chosen)
                    if(fourOfAKindt == -1){
                        cout << "Four of a kind! " << total << "points! Y/N";
                        cin >> takePoints;
                        if(takePoints != 'N' || takePoints != 'n'){
                            fourOfAKind = total;
                            endTurn = true;
                        }else{
                            FP = true;
                        }
                    }
                }
            }
            //if three dice are the same:
            //check full house. (if available, offer and end turn if chosen)
            //offer three of a kind
            if(!endTurn){
                //Full house (d4 == d5)
                if(d4 == d5 && fullHouse == -1){
                    cout << "Full House! 25 points! Y/N";
                    cin >> takePoints;
                    if(takePoints != 'N' || takePoints != 'n'){
                        fullHouse = FULLHOUSE;
                        endTurn = true;
                    }else {
                        FHP = true;
                    }
                }
                //three of a kind
                if(threeOfAKind == -1){
                    cout << "Three of a kind! " << total << "points! Y/N";
                    cin >> takePoints;
                    if(takePoints != 'N' || takePoints != 'n'){
                        threeOfAKind = total;
                        endTurn = true;
                    }else {
                        TP = true;
                    }
                }
            }
        }
        if(!endTurn){
            //Full house (d3 == d4 == d5)
            if(d3 == d4 && d4 == d5 && fullHouse == -1){
                cout << "Full House! 25 points! Y/N";
                cin >> takePoints;
                if(takePoints != 'N' || takePoints != 'n'){
                    fullHouse = FULLHOUSE;
                    endTurn = true;
                }else{
                    FHP = true;
                }
            }
        }
    }else if(d2 == d3){
        if(d3 == d4){
            if(d4 == d5){
                //if four dice are the same, display and offer four of a kind if available (end turn if chosen)
                if(fourOfAKind == -1){
                    cout << "Four of a kind! " << total << "points! Y/N";
                    cin >> takePoints;
                    if(takePoints != 'N' || takePoints != 'n'){
                        fourOfAKind = total;
                        endTurn = true;
                    }else{
                        FP = true;
                    }
                }
                if(!endTurn){
                //three of a kind
                    if(threeOfAKind == -1){
                        cout << "Three of a kind! " << total << "points! Y/N";
                        cin >> takePoints;
                        if(takePoints != 'N' || takePoints != 'n'){
                            threeOfAKind = total;
                            endTurn = true;
                        }else{
                            TP = true;
                        }
                    }
                }
            }
        }
    }else if(d3 == d4){
        if(d4 == d5){
            //three of a kind
            if(threeOfAKind == -1){
                cout << "Three of a kind! " << total << "points! Y/N";
                cin >> takePoints;
                if(takePoints != 'N' || takePoints != 'n'){
                    threeOfAKind = total;
                    endTurn = true;
                }else{
                    TP = true;
                }
            }
        }
    }
    if(!endTurn){//display dice again and offer availble from this list "(C)hance:(value) (O)nes:(value) (t)wos:(value) (T)hrees:(value) (f)ours:(value) (F)ives:(value) (S)ixes:(value) or (Z)ero"
            //if none above available or (Z)ero chosen, display all other available options and choose where to take a zero. Run logic again for zero taken to avoid unnecessarry zeros
        int o, t, T, f, F, s;
        switch (d1){
            case 1:{
                o += d1;
                break;
            }case 2:{
                t += d1;
                break;
            }case 3:{
                T += d1;
                break;
            }case 4:{
                f += d1;
                break;
            }default:{
                (d1 == 5) ? (F += d1) : (s += d1);
            }
        }
        switch (d2){
            case 1:{
                o += d2;
                break;
            }case 2:{
                t += d2;
                break;
            }case 3:{
                T += d2;
                break;
            }case 4:{
                f += d2;
                break;
            }default:{
                (d2 == 5) ? (F += d2) : (s += d2);
            }
        }
        switch (d3){
            case 1:{
                o += d3;
                break;
            }case 2:{
                t += d3;
                break;
            }case 3:{
                T += d3;
                break;
            }case 4:{
                f += d3;
                break;
            }default:{
                (d3 == 5) ? (F += d3) : (s += d3);
            }
        }
        switch (d4){
            case 1:{
                o += d4;
                break;
            }case 2:{
                t += d4;
                break;
            }case 3:{
                T += d4;
                break;
            }case 4:{
                f += d4;
                break;
            }default:{
                (d4 == 5) ? (F += d4) : (s += d4);
            }
        }
        switch (d5){
            case 1:{
                o += d5;
                break;
            }case 2:{
                t += d5;
                break;
            }case 3:{
                T += d5;
                break;
            }case 4:{
                f += d5;
                break;
            }default:{
                (d5 == 5) ? (F += d5) : (s += d5);
            }
        }
        cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << ' ' << d5 << endl;
        bool available;
        if(chance == 0){
            cout << "(C)hance: " << total << ' ';
            available = true;
        }
        if(ones == -1 && o != 0){
            cout << "(o)nes: " << o << ' ';
            available = true;
        }
        if(twos == -1 && t != 0){
            cout << "(t)wos: " << t << ' ';
            available = true;
        }
        if(threes == -1 && T != 0){
            cout << "(T)hrees: " << T << ' ';
            available = true;
        }
        if(fours == -1 && f != 0){
            cout << "(f)ours: " << f << ' ';
            available = true;
        }
        if(fives == -1 && F != 0){
            cout << "(F)ives: " << F << ' ';
            available = true;
        }
        if(sixes == -1 && s != 0){
            cout << "(s)ixes: " << s << ' ';
            available = true;
        }
        if(available == true){
            cout << "or (Z)ero\n"
            cin >> takePoints;
        }else {takePoints = 'Z'};
        switch (takePoints){
            case 'C':{
                if(chance == 0){
                    cout << "Chance: " << total << ' points!' << endl;
                    chance = total;
                }else{
                    takePoints = 'Z';
                }
                break;
            }case 'o':{
                if(ones == -1 && o != 0){
                    cout << "Ones: " << o << ' points!' << endl;
                    ones = o;
                }else{
                    takePoints = 'Z';
                }
                break;
            }case 't':{
                if(twos == -1 && t != 0){
                    cout << "Twos: " << t << ' points!' << endl;
                    twos = t;
                }else{
                    takePoints = 'Z';
                }
                break;
            }case 'T':{
                if(threes == -1 && T != 0){
                    cout << "Threes: " << T << ' points!' << endl;
                    threes = T;
                }else{
                    takePoints = 'Z';
                }
                break;
            }case 'f':{
                if(fours == -1 && f != 0){
                    cout << "Fours: " << f << ' points!' << endl;
                    fours = f;
                }else{
                    takePoints = 'Z';
                }
                break;
            }case 'F':{
                if(fives == -1 && F != 0){
                    cout << "Fives: " << F << ' points!' << endl;
                    fives = F;
                }else{
                    takePoints = 'Z';
                }
                break;
            }case 's':{
                if(sixes == -1 && s != 0){
                    cout << "Sixes: " << s << ' points!' << endl;
                    sixes = s;
                }else{
                    takePoints = 'Z';
                }
                break;
            }
        }
    }
};

YahtzeePlayer::YahtzeePlayer(int  numPlayers, bool &computerPlayer){
    if (numPlayers > 1){
        cout << "Player name: "; //Get player name
        cin >> name;
        turnorder = new YahtzeePlayer((numPlayers - 1), computerPlayer); //Recursion to create last player first and set player order
        computer = false;
        endPlayer = false;
    }else{
        computer = computerPlayer;
        if(computer != true){ //If the last player is a computer, skip
            cout << "Player name: ";
            cin >> name;
            endPlayer = true; //Announce this is the last player
        }
        computerPlayer = false;
    }
};

void playYahtzee(int numPlayers, bool computerPlayer){
    bool cpu = computerPlayer; 
    YahtzeePlayer Game1(numPlayers, cpu);
    for(Game1.turnsToGo; Game1.turnsToGo != 0; Game1.turnsToGo--){
        Game1.Pturn();
    }
    Game1.endGame();
}


void YahtzeePlayer::Cturn(){

};
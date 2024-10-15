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
    }else{
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
    cout << upperTotal << endl << lowerTotal << endl << total;
}; //calculating totals

void YahtzeePlayer::chooseScore(int d1, int d2, int d3, int d4, int d5){
    //sort dice in ascending order with temp variables. check sm straight or lg straight (if available, set and end turn)
    //check number of same type dice
        //if all dice are the same and Yahtzee has not been set to 0 or 50, yahtzee = 50. End turn
            // if all dice are the same and Yahtzee is 50, add Yahtzee bonus, but don't end turn
        //if four dice are the same, display and offer four of a kind if available (end turn if chosen)
        //if three dice are the same:
            //check full house. (if available, offer and end turn if chosen)
            //offer three of a kind
        //display dice again and offer availble from this list "(C)hance:(value) (O)nes:(value) (t)wos:(value) (T)hrees:(value) (f)ours:(value) (F)ives:(value) (S)ixes:(value) or (Z)ero"
            //if none above available or (Z)ero chosen, display all other available options and choose where to take a zero
};

YahtzeePlayer::YahtzeePlayer(int  numPlayers, bool &computerPlayer){
    if (numPlayers > 1){
        cout << "Player name: ";
        cin >> this->name;
        YahtzeePlayer next((numPlayers - 1), computerPlayer);
        turnorder = &next;
        computer = false;
    }else{
        computer = computerPlayer;
        computerPlayer = false;
    }
}

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

int Dice::roll(){
    this->value = rand() % 6;
};
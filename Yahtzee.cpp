void YahtzeePlayer::Pturn(){ //roll logic and save dice logic, call other functions
    Dice d1, d2, d3, d4, d5;
    int i = 0;
    for(i; i < 3; i++){
        if(d1.save != true){
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
        if(i == 2){
            break;
        }else{
            cout << "Push Y/N for each dice to save it (No spaces, e.g. YNYYN)" << endl;
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
                break;
            }
        }
    }
    char x = chooseScore(d1.value, d2.value, d3.value, d4.value, d5.value);
    if(turnorder->computer){
        turnorder->Cturn();
    }else{
        turnorder->Pturn();
    }
};

void YahtzeePlayer::endGame(){

}; //calculating totals

char YahtzeePlayer::chooseScore(int d1, int d2, int d3, int d4, int d5){

};

YahtzeePlayer::YahtzeePlayer(int  numPlayers, bool &computerPlayer){
    if (numPlayers > 1){
        YahtzeePlayer next((numPlayers - 1), computerPlayer);
        turnorder = &next;
        computer = false;
    }else{
        computer = computerPlayer;
        computerPlayer == false;
    }
}

void playYahtzee(int numPlayers, bool computerPlayer){



}


void YahtzeePlayer::Cturn(){

};

int Dice::roll(){
    this->value = rand() % 6;
};


void round(int numPlayers);

void endgame(int numPlayers);
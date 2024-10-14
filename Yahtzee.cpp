void YahtzeePlayer::Pturn(){ //roll logic and save dice logic, call other functions
    int d1, d2, d3, d4, d5;
    //TODO
    if(d1 == d2 && d2 == d3 && d3 == d4 && d4 == d5){
        Yahtzee();
        // endturn switch
    }
    //TODO place score somewhere
};

void YahtzeePlayer::endGame(){

}; //calculating totals

void YahtzeePlayer::Yahtzee(){}; //if Yahtzee = null, Yahtzee can be set to 50, if Yahtzee = 0, Yahtzee is not an option, if Yahtzee = 50, yahtzeeBonus += 100 and add score elsewhere

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


void round(int numPlayers);

void endgame(int numPlayers);
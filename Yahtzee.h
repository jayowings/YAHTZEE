

enum LOWER{FULLHOUSE = 25, SMSTRAIGHT = 30, LGSTRAIGHT = 40, YAHTZEE = 50, BONUS = 100, FAIL = 0, UPPERBONUS = 35};

class Dice{
    public:
        int value;
        bool save = false;
        int roll();
};

class YahtzeePlayer{
    private:
        int ones, twos, threes, fours, fives, sixes;
        int threeOfAKind, fourOfAKind, fullHouse, smallStaight, largeStraight, yahtzee, yahtzeeBonus, Chance;
        int upperTotal, lowerTotal, total;
        char chooseScore(int d1, int d2, int d3, int d4, int d5);
        YahtzeePlayer * turnorder;
    public:
        int turnsToGo = 13;
        bool computer;
        void Pturn();
        void Cturn();
        void endGame();
        YahtzeePlayer(int numPlayers, bool &computerPlayer);
};

void round(int numPlayers);

void endgame(int numPlayers);

void playYahtzee(int numPlayers, bool computerPlayer);

#include "Yahtzee.cpp"
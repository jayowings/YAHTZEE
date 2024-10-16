#include "Dice.h"

enum LOWER{FULLHOUSE = 25, SMSTRAIGHT = 30, LGSTRAIGHT = 40, YAHTZEE = 50, BONUS = 100, FAIL = 0, UPPERBONUS = 35};

class YahtzeePlayer{
    private:
        int ones, twos, threes, fours, fives, sixes;
        int threeOfAKind = -1, fourOfAKind = -1, fullHouse = -1, smallStraight = -1, largeStraight = -1, yahtzee = -1, yahtzeeBonus, Chance;
        int upperTotal, lowerTotal, total;
        YahtzeePlayer * turnorder;
        bool endPlayer;
        void Cturn();
        void chooseScore(int d1, int d2, int d3, int d4, int d5);
    public:
        string name;
        bool computer;
        int turnsToGo = 13;
        void Pturn();
        void endGame();
        YahtzeePlayer(int numPlayers, bool &computerPlayer);
};

void endgame(int numPlayers);

void playYahtzee(int numPlayers, bool computerPlayer);

#include "Yahtzee.cpp"
#include <iostream>
#include "GameManager.cpp"
#include "dice.cpp"
using namespace std;

int main(int argc, char **argv)
{
    GameManager cantStop = GameManager();
    Dice dice = Dice();




    //roll dice and find combinations
    vector<vector<int>> diceCombinations;
    while (true)
    {
        dice.roll();
        dice.display();
        diceCombinations = dice.checkCombinations();
        cantStop.playTurn(diceCombinations);
        cantStop.display();
    }
    
    
    
}
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
        if (cantStop.score[1-cantStop.currentPLayer] == 3) //curent player is already switched, but check if previous player won before allowing him to play
        {
            cout << "Player " << cantStop.currentPLayer << " Won!" << endl;
            break;
        }
    }
    
    
    
}
#include <iostream>
#include "GameManager.cpp"
using namespace std;

int main(int argc, char **argv)
{
    GameManager cantStop = GameManager();


    //roll dice and find combinations
    vector<vector<int>> diceCombinations = {{2,6},{4,10},{3,7}};
    while (true)
    {
        cantStop.playTurn(diceCombinations);
        cantStop.display();
    }
    
    
    
}
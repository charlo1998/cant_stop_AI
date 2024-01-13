#include "dice.hpp"
Dice::Dice(){
    this->nDice = 4; //nombre de des lances dans le jeu (toujours 4)
}

vector<vector<int>> Dice::checkCombinations(vector<int> results){
    vector<vector<int>> combinations;
    for (int i = 1; i < nDice; i++){
        int colonne2;
        int colonne1 = results[0] + results[i];
        vector<int> choix;
        if(i == 1){
            colonne2 = results[2]+results[3];
            choix.push_back(colonne1);
            choix.push_back(colonne2);
        }
        else if (i == 2){
            colonne2 = results[1]+results[3];
            choix.push_back(colonne1);
            choix.push_back(colonne2);
        }
        else{
            colonne2 = results[1] + results[2];
            choix.push_back(colonne1);
            choix.push_back(colonne2);
        }

        combinations.push_back(choix);       
    }
}

/**
 * Dice class
 * takes the roll of the 4 dices used in the can't stop game. The dice can be rolled via the roll() function,
 * and the list of the possible columns pairs in which a player can advance is given by the checkCombinations function
*/

#include "dice.hpp"
/**
 * class constructor
*/
Dice::Dice(){
    this->nDice = 4; //number of dice in the game (always 4)
    this->dice = {0,0,0,0};
    srand(time(0)); //seed rand()
    roll();

}
/**
 * rolls 4 dice
 * 
*/
void Dice::roll(){
    for(int i = 0; i < 4; i++){
        dice[i] = ((rand() % 6) + 1);
    }
}

void Dice::display(){
    cout << "rolled: ";
    for(int i = 0; i < 4; i++){
        cout << dice[i] << " "; 
    }
    cout << endl;
}

/**
 * Checks dice results and returns possible combinations of dice for column advance
 * 
 * @param empty
 * 
 * @return all increasingly ordered different pairs of two dice added together
*/

vector<vector<int>> Dice::checkCombinations(){
    vector<vector<int>> combinations;
    for (int i = 1; i < nDice; i++){    //look for all different combinations of two pairs of dice
        int colonne2;
        int colonne1 = dice[0] + dice[i];
        vector<int> choix;
        if(i == 1){
            colonne2 = dice[2]+dice[3];
            if(colonne1<colonne2){          //order the dice in increasing order
                choix.push_back(colonne1);
                choix.push_back(colonne2);
            }
            else{
                choix.push_back(colonne2);
                choix.push_back(colonne1);
            }
        }
        else if (i == 2){
            colonne2 = dice[1]+dice[3];
            if(colonne1<colonne2){          //order the dice in increasing order
                choix.push_back(colonne1);
                choix.push_back(colonne2);
            }
            else{
                choix.push_back(colonne2);
                choix.push_back(colonne1);
            }
        }
        else{
            colonne2 = dice[1] + dice[2];
            if(colonne1<colonne2){
                choix.push_back(colonne1);
                choix.push_back(colonne2);
            }
            else{
                choix.push_back(colonne2);
                choix.push_back(colonne1);
            }
        }

        if (combinations.size() == 0){  //if it is the first combination add it to the list
            combinations.push_back(choix);
        }

        else{           //else check wether this pair of column is already possible via another combination
            int k = 0;
            while(combinations[k] != choix && k < combinations.size()){
                k++;
            }
            if(k == combinations.size()){
                combinations.push_back(choix);
            }
        }
    }
    return combinations;
}

/**
 * return the results on the dice as a string 
*/
string Dice::toString(){
    string s = "";
    for(auto d : dice){
        string c = to_string(d);
        s = s + c + " ";
    }

    return s;
}

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  //to re-seed rand()

using namespace std;

class Dice {
public:
    Dice();
    int nDice;
    vector<int> dice;
    ~Dice(){};
    void roll();
    vector<vector<int>> checkCombinations();
    string toString();
};
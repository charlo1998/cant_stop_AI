#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dice {
public:
    Dice();
    vector<vector<int>> checkCombinations(vector<int> results);
    int nDice;
    ~Dice(){};
};
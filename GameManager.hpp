#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class GameManager {
public:
    vector<int> firstPlayerTracks;
    vector<int> secondPlayerTracks;
    vector<int> currentProgress;
    bool currentPLayer;
    vector<int> goalPerTrack;
    vector<int> score;

    GameManager();
    void display();
    ~GameManager(){};
    vector<vector<int>> canAdvanceCubes(vector<int> tracks);
    void saveProgress();
    vector<vector<int>> findMoves(vector<vector<int>> diceCombinations);
    void playTurn(vector<vector<int>> diceCombinations);
};
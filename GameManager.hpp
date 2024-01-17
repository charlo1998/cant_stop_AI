#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class GameManager {
public:
    vector<int> firstPlayerTracks;
    vector<int> secondPlayerTracks;
    vector<int> currentProgress;
    vector<int> goalPerTrack;
    vector<int> score;

    GameManager();
    void display();
    ~GameManager(){};
    vector<int> canAdvanceCubes(vector<int> tracks, bool currentPLayer);
    void saveProgress(bool currentPLayer);
    vector<vector<int>> findMoves(vector<vector<int>> diceCombinations, bool currentPLayer);
};
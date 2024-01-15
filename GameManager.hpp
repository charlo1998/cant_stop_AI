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
    void advanceCubes(vector<int> tracks);
    void saveProgress(bool currentPLayer);
    void findMoves(vector<int> diceCombinations, bool currentPLayer);
};
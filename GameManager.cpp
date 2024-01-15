#include "GameManager.hpp"

GameManager::GameManager(){
    this->firstPlayerTracks = {0,0,0,0,0,0,0,0,0,0,0};
    this->secondPlayerTracks = {0,0,0,0,0,0,0,0,0,0,0};
    this->currentProgress = {0,0,0,0,0,0,0,0,0,0,0};
    this->goalPerTrack = {3,5,7,9,11,13,11,9,7,5,3};
    this->score = {0,0};

    display();
}

void GameManager::display(){
    cout << "---------- game state ------------" << endl;

    cout << "First player progress: ";
    for (size_t i = 0; i < firstPlayerTracks.size(); i++)
    {
        cout << firstPlayerTracks[i] << " ";
    }
    cout << endl;
    cout << "completed " << score[0] << " tracks" << endl;

    cout << "Second player progress: ";
    for (size_t i = 0; i < secondPlayerTracks.size(); i++)
    {
        cout << secondPlayerTracks[i] << " ";
    }
    cout << endl;
    cout << "completed " << score[1] << " tracks" << endl;
}

void GameManager::advanceCubes(vector<int> tracks){
    //takes a vector of the tracks where we want to advance, and advance the given player in those tracks.

    //make temporary progress
    for (auto &track : tracks)
    {
        currentProgress[track]++;
    }
    
}

void GameManager::saveProgress(bool currentPLayer){
    //Save current progress into current player tracks and prepare progress vector for next player
    if (currentPLayer == 0)
    {
        firstPlayerTracks = currentProgress;
        currentProgress = secondPlayerTracks; 
    } else {
        secondPlayerTracks = currentProgress;
        currentProgress = firstPlayerTracks;
    }
    
}

void GameManager::findMoves(vector<int> diceCombinations, bool currentPLayer){
    //takes a vector of the possible combinations with a given dice throw (example below) and find the possible legal moves.
    //returns a vector of the possible moves (a vector containing the indices of the tracks in which we will advance)
    //example: the dice roll 1,2,3,4. possible combinations are {{3,7}, {4,6}, {5,5}}, which is given as input to findMoves.
    //Say tracks 5 and 4 are completed. findMoves will return {{3,7}, {6}}. In case of no legal move, will return {0}.


    for (auto &move : diceCombinations)
    {
        //validate this move is legal.
        if (currentProgress[track] == goalPerTrack[track])
        {
            cout << "cannot advance on track " << track << ", player " << currentPLayer << " already completed it." << endl;
            continue; //jump to next advance action
        }
    }
    
}
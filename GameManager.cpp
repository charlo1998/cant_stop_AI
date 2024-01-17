#include "GameManager.hpp"

GameManager::GameManager(){
    this->firstPlayerTracks = {0,0,0,0,0,0,0,0,0,0,0};
    this->secondPlayerTracks = {0,0,0,0,0,0,0,0,0,0,0};
    this->currentProgress = {0,0,0,0,0,0,0,0,0,0,0};
    this->goalPerTrack = {3,5,7,9,11,13,11,9,7,5,3};
    this->score = {0,0};
    this->currentPLayer = 0;

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

    cout << "it is player " << currentPLayer << "'s turn." << endl;
    cout << "current progress: ";
    for (size_t i = 0; i < secondPlayerTracks.size(); i++)
    {
        cout << currentProgress[i] << " ";
    }
    cout << endl;
    
}

vector<int> GameManager::canAdvanceCubes(vector<int> tracks){
    //takes a vector of the tracks where we want to advance, and advance the given player in those tracks.

    vector<int> advancedtracks;
    //select the correct tracks according to the current player
    vector<int> currentPlayerTracks;
    vector<int> otherPlayerTracks;
    if (currentPLayer == 0)
    {
        currentPlayerTracks = firstPlayerTracks;
        otherPlayerTracks = secondPlayerTracks;
    } else {
        currentPlayerTracks = secondPlayerTracks;
        otherPlayerTracks = firstPlayerTracks;
    }
    

    //find which columns we are currently making progress on
    vector<int> progressColumns;
    for (size_t i = 0; i < goalPerTrack.size(); i++)
    {
        if (currentProgress[i] > currentPlayerTracks[i])
        {
            progressColumns.push_back(i+2);
        }
        
    }
    
    
    //validate we can make temporary progress
    for (auto &track : tracks)
    {
        track = track-2; //convert to internal representation
        if (currentPlayerTracks[track] == goalPerTrack[track])
        {
            cout << "cannot advance on track " << track+2 << ", player " << currentPLayer << " already completed it." << endl;
            continue; //jump to next advance action
        }
        else if (currentProgress[track] == goalPerTrack[track])
        {
            cout << "cannot advance on track " << track+2 << ", current progress already reached the end." << endl;
            continue; //jump to next advance action
        } else if (otherPlayerTracks[track] == goalPerTrack[track])
        {
            cout << "cannot advance on track " << track+2 << ", player " << 1-currentPLayer << " already completed it." << endl;
            continue; //jump to next advance action
        }
        
        std::vector<int>::iterator it;
        it = find(progressColumns.begin(), progressColumns.end(), track);
        
        if (it == progressColumns.end()) //didn't find track in the current tracks we are progressing in, check if we can add it.
        {
            if (progressColumns.size() == 3)
            {
                cout << "cannot advance on track " << track+2 << ", already making progress on 3 columns." << endl;
                continue;
            }
        }
        
        advancedtracks.push_back(track+2);
        
    }
    
    if (advancedtracks.size() != 0)
    {
        return advancedtracks;
    } else {
        return {0};
    }
    
}

void GameManager::saveProgress(){
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

vector<vector<int>> GameManager::findMoves(vector<vector<int>> diceCombinations){
    //takes a vector of the possible combinations with a given dice throw (example below) and find the possible legal moves.
    //returns a vector of the possible moves (a vector containing the indices of the tracks in which we will advance)
    //example: the dice roll 1,2,3,4. possible combinations are {{3,7}, {4,6}, {5,5}}, which is given as input to findMoves.
    //Say tracks 5 and 4 are completed. findMoves will return {{3,7}, {6}}. In case of no legal move, will return {0}.

    vector<vector<int>> legalMoves;
    for (auto &move : diceCombinations)
    {
        //validate this move is legal.
        vector<int> outcome = canAdvanceCubes(move);
        if (outcome[0] != 0)
        {
            legalMoves.push_back(outcome);
        }
        
    }
    

    return legalMoves;
}

void GameManager::playTurn(vector<vector<int>> diceCombinations){

    cout << "----------------------------------------------------------" << endl;
    cout << "it is player " << currentPLayer << "'s turn." << endl;

    vector<vector<int>> legalMoves = findMoves(diceCombinations);

    if (legalMoves.size() == 0)
    {
        cout << "no legal move available! losing progress and ending turn!" << endl;
        currentPLayer = 1 - currentPLayer;
        if (currentPLayer == 0)
        {
            currentProgress = firstPlayerTracks;
        } else {
            currentProgress = secondPlayerTracks;
        }
        
        return;
    }

    cout << "move 0: stop and save progress." << endl;
    
    for (size_t i = 0; i < legalMoves.size(); i++)
    {
        cout << "move " << i+1 << ": advance on track.s ";
        for (size_t j = 0; j < legalMoves[i].size(); j++)
        {
            cout << legalMoves[i][j] << ", ";
        }
        cout << endl;
    }

    

    bool validAction = false;
    int action;
    while (validAction == false)
    {
        int action;
        cout << "please input the number corresponding to the wanted action." << endl;
        cin >> action;
        if (cin.fail())
        {
            cout << "not a valid move!" << endl;
            cin.clear();
            cin.ignore(256,'\n');
        } else if (action > legalMoves.size())
        {
            cout << "not a valid move!" << endl;
        } else {
            validAction = true;
        }
    }
    
    

    if (action==0)
    {
        saveProgress();
        currentPLayer = 1 - currentPLayer;
    } else {
        for (size_t i = 0; i < legalMoves[action].size(); i++)
        {
            currentProgress[i]++;
            cout << "progressed in track " << i+2 << endl;
        }
        
    }

}
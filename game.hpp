#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Die {
public:
    Die(vector<string> faces);
    vector<string> faces;
    string faceUp;
    void roll();
    void display();
    ~Die(){};
};

class Game {
public:
    Game(vector<Die> dice);
    vector<Die> dice;
    void start();
    void display();
    ~Game(){};
};
#include "game.hpp"
Die::Die(vector<string> faces){
    this->faces = faces;
    this->faceUp = -1;
    roll();
    display();
}

void Die::roll(){

    // Generate a random number between 0 and 5
    int randomNumber = std::rand() % 6;

    faceUp = faces[randomNumber];
}

void Die::display(){
    cout << "Die with faces "<< faces[0]<< faces[1]<< faces[2]<< faces[3]<< faces[4]<< faces[5] <<" rolled a "<<faceUp <<endl;
}

Game::Game(vector<Die> dice){
    this->dice = dice;
    start();
    display();
}

void Game::start(){
        if (dice.size() != 16)
    {
        std::cout << "Wrong number of dice! must be 4x4."; //TODO: throw an exception
    }
    
}

void Game::display(){
    std::cout << "--------- new game! -----------" << std::endl;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << dice[j+4*i].faceUp << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------- --------- -----------" << std::endl;
}

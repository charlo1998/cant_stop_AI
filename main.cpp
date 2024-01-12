#include <iostream>
#include "game.cpp"
using namespace std;

int main(int argc, char **argv)
{
    // Seed the random number generator
    std::srand(std::time(0));

    //create 16 dice
    vector<Die> dice;
    for (size_t i = 0; i < 16; i++)
    {
        //6 faces per die
        vector<string> faces = {};
        for (size_t j = 0; j < 6; j++)
        {
            char randomChar = 'A' + rand()%26;
            string letter(1, randomChar);
            faces.push_back(letter);
        }
        Die die = Die(faces);
        dice.push_back(die);
        
    }
    


    Game game = Game(dice);
    
}
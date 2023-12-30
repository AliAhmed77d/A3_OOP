#include <iostream>
#include <vector>
#include <algorithm>
#include<random>

using namespace std;

AiPlayer5x5::AiPlayer5x5 (char symbol, X_O_5x5_Board *board):Player(symbol)
{
    this->name = "Random Computer Player";
    this->board = board;
    cout << "My names is " << name << endl;
}

// Generate a random move
void AiPlayer5x5::get_move (int& x, int& y) {
    vector<pair<int,int>> moves = board->getAvailableMoves();
    cout << "found " << moves.size() << "moves,";
    vector<vector<int>> weights;
    int biggestWeight = 0;
    for(auto& move : moves){
        int weight = board->get_move_points(move.first,move.second, toupper(symbol));
        cout << move.first << " " << move.second << " " << weight << endl;
        if(weight < biggestWeight) continue;
        if(weight > biggestWeight) {
            biggestWeight = weight;
            weights.clear();
        };
        weights.push_back(vector<int>{move.first,move.second,weight});
    }
    cout << weights.size() << "out of them are best choices with " << biggestWeight << " points" << endl;

    //choose random index from the best choices
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rnd(0, weights.size() - 1);

    int index = rnd(gen);
    x = weights[index][0];
    y = weights[index][1];
}

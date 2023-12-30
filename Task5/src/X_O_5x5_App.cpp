// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "AiPlayer5x5.cpp"
using namespace std;

void XO5x5start(){
    int choice;

    Player* players[2];
    players[0] = new Player (1, 'x');
    Board *board =  new X_O_5x5_Board();
    cout << "Welcome to 5x5 X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer , 2 if you want to play with Ai: ";
    cin >> choice;
    if (choice == 1)
        players[1] = new RandomPlayer ('o', 5);
    else if(choice == 2)
        players[1] = new AiPlayer5x5 ('o', dynamic_cast<X_O_5x5_Board*>(board));
    else
        players[1] = new Player (2, 'o');
        //Player pointer points to child


    GameManager x_o_game (board, players);
    x_o_game.run();
    system ("pause");
}
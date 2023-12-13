// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"

using namespace std;

void XO5x5start(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to 5x5 X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new X_O_5x5_Board(), players);
    x_o_game.run();
    system ("pause");
}
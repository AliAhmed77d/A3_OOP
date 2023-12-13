#include <iostream>
#include "src/X_O_5x5_App.cpp" // 5X5 Game
#include "src/X_O_5x5_Board.cpp"
#include "src/X_O_App.cpp"     // XO Game
#include "src/X_O_Board.cpp"
#include "src/Player.cpp"
#include "src/RandomPlayer.cpp"
#include "src/GameManager.cpp"

using namespace std;

int main() {
    int choice;
    cout << "1) XO game 2) 5X5 game" << endl;
    cin >> choice;
    if(choice == 1)
        XOstart();
    else if(choice == 2)
        XO5x5start();
}



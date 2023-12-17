#include <iostream>
#include "src/X_O_5x5_App.cpp" // 5X5 Game
#include "src/X_O_5x5_Board.cpp"
#include "src/X_O_App.cpp"     // XO Game
#include "src/X_O_Board.cpp"
#include "src/Player.cpp"
#include "src/RandomPlayer.cpp"
#include "src/GameManager.cpp"
#include "src/pyramid_x_o.cpp"
#include "src/four in arrow.cpp"


using namespace std;

int main() {
    int choice;
    cout << "1) XO game \n2) 5X5 game \n3)Pyramid xo \n4) four in a row " << endl;
    cin >> choice;
    if(choice == 1)
        XOstart();
    else if(choice == 2)
        XO5x5start();
    else if(choice == 3)
        pyramic_X_O();
    else if(choice == 4)
        four_in_a_row();
}



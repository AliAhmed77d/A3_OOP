#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

string player_Name;
int currentPlayer = 1;

void drawBoard() {
    cout << "X-O Game\n";
    cout << "---------\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------\n";
}

bool isMoveValid(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    return board[row][col] == '1' + move - 1;
}

bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

void makeMove(int move, char symbol) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    board[row][col] = symbol;
}

int getPlayerMove() {
    int move;
    cout << player_Name << ", select your move from 1 to 9 : ";
    cin >> move;
    return move;
}

int getComputerMove() {
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!isMoveValid(move));
    return move;
}

void pyramic_X_O() {
    srand(time(0));

    cout << "Enter the name of the player: ";
    cin >> player_Name;

    while (true) {
        drawBoard();

        int move;
        if (currentPlayer == 1) {
            move = getPlayerMove();
        } else {
            move = getComputerMove();
        }

        if (!isMoveValid(move)) {
            cout << "Wrong move. Try again, please.\n";
            continue;
        }

        char symbol = (currentPlayer == 1) ? 'X' : 'O';
        makeMove(move, symbol);

        if (checkWin()) {
            drawBoard();
            cout << player_Name << " wins GG have a good day.\n";
            break;
        } else if (isBoardFull()) {
            drawBoard();
            cout << "draw\n";
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}
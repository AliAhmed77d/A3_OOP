
#ifndef BOARD_H
#define BOARD_H

void drawBoard();
bool isMoveValid(int move);
bool isBoardFull();
bool checkWin();
void makeMove(int move, char symbol);

#endif 


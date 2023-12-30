#include <iostream>
#include <utility>
#include <vector>

X_O_5x5_Board::X_O_5x5_Board() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for(int i = 0 ; i < n_rows ; i++){
        board[i] = new char[n_cols];
        for(int j = 0 ; j < n_cols ; j++)
            board[i][j] = 0;
    }
}

bool X_O_5x5_Board::isCellInBoard(int x , int y) {
    return (x >= 0 && x < n_cols) && (y >= 0 && y < n_rows);
}

bool X_O_5x5_Board::update_board(int x, int y, char mark) {
    if(isCellInBoard(x,y) && (board[x][y] == 0)){
        board[x][y] = toupper(mark);
        if(mark == 'x')
            x_points += get_move_points(x,y,toupper(mark));
        else
            o_points += get_move_points(x,y,toupper(mark));

        n_moves++;
        return true;
    }
    return false;
}

void X_O_5x5_Board::display_board() {
    string border = "---------------------";
    cout << border << endl << " |";
    for(int i = 0 ; i < n_cols; i++)
        cout << i <<"|";
    cout << endl;
    for(int i = 0 ; i < n_cols ; i++){
        cout << i << "|";
        for(int j = 0 ; j < n_rows ; j++){
            char mark = (board[i][j] == 0 ) ? ' ' : toupper(board[i][j]);
            cout << mark << "|";
        }
        cout << endl;
    }
    cout << "X : " << x_points << " | O : " << o_points << endl;
    cout << border << endl;
}

int X_O_5x5_Board::get_move_points(int x,int y,char mark){
    int points = 0;
    pair<int,int> pairs[3]= {pair<int,int>(-2,-1),pair<int,int>(-1,1),pair<int,int>(1,2)};

    // up and down
    for(auto & pair : pairs){
        int first = pair.first;
        int second = pair.second;
        if(isCellInBoard(x,y+first) && (board[x][y+first] == mark))
            if(isCellInBoard(x,y+second) && (board[x][y+second] == mark))
                points++;
    }

    //left and right
    for(auto & pair : pairs){
        int first = pair.first;
        int second = pair.second;
        if(isCellInBoard(x+first,y) && (board[x+first][y] == mark))
            if(isCellInBoard(x+second,y) && (board[x+second][y] == mark))
                points++;
    }

    // positive diagonal line
    for(auto & pair : pairs){
        int first = pair.first;
        int second = pair.second;
        if(isCellInBoard(x+first,y+first) && (board[x+first][y+first] == mark))
            if(isCellInBoard(x+second,y+second) && (board[x+second][y+second] == mark))
                points++;
    }

    // negative diagonal line
    for(auto & pair : pairs){
        int first = pair.first;
        int second = pair.second;
        if(isCellInBoard(x+first,y-first) && (board[x+first][y-first] == mark))
            if(isCellInBoard(x+second,y-second) && (board[x+second][y-second] == mark))
                points++;
    }

    return points;
}

vector<pair<int,int>> X_O_5x5_Board::getAvailableMoves(){
    vector<pair<int,int>> moves;
    for(int i = 0 ; i < n_cols ; i++){
        for(int j = 0 ; j < n_rows ; j++){
            if(board[i][j] == 0 ){
                moves.emplace_back(i,j);
            }
        }
    }
    return  moves;
}


int X_O_5x5_Board::getXPoints() const {
    return x_points;
}

int X_O_5x5_Board::getOPoints() const {
    return o_points;
}

bool X_O_5x5_Board::is_winner() {
    if (game_is_over() && ((getXPoints() > getOPoints()) || (getOPoints() > getXPoints()))){
        cout << ((getXPoints() > getOPoints()) ? 'X' : 'O') << " won the game!" << endl;
        return true;
    }
    return false;
}

bool X_O_5x5_Board::is_draw() {
    return (game_is_over() && !is_winner());
}


bool X_O_5x5_Board::game_is_over() {
    return n_moves >= 24;
}

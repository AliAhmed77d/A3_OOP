// File name:   A3_SheetPb6_20210944.cpp
// Purpose:     Game of life
// Author(s):   Mohammed Ahmed El-mustafa
// ID(s):       20210944
// Section:     S15
// Date:        12/5/2023
// Version:     1

#include <iostream>
#include <vector>


using namespace std;

enum class State {
    Dead , Alive
};

class Universe{
    int width;
    int height;
    int turn = 0;
    vector<vector<State>> layout;

    public:
        Universe(int width , int height) : width(width) , height(height){};

        void initialize(){
            for(int i = 0 ; i < height ; i++){
                layout.emplace_back();
                for (int j = 0; j < width; ++j) {
                    layout[i].push_back(State::Dead);
                }
                cout << endl;
            }
        }

        void reset(){
            initialize();
            turn = 0 ;
        }

        bool isCellInLayout(int x , int y) const{
            return (x >= 0 && y >= 0 ) && (x < height && y < width);
        }

        int count_neighbors(int x,int y){
            int neighbors = 0;
            // Upper neighbors
            for(int i = -1 ; i < 2 ; i++){
                int newY = y+i;
                int newX = x-1;
                if(isCellInLayout(newX,newY))
                    if(layout[newX][newY] == State::Alive)
                        neighbors++;
            }
            // Same level neighbors
            for(int i = -1 ; i < 2 ; i = i +2){
                int newY = y+i;
                int newX = x;
                if(isCellInLayout(newX,newY))
                    if(layout[newX][newY] == State::Alive)
                        neighbors++;
            }
            // Lower neighbors
            for(int i = -1 ; i < 2 ; i++){
                int newY = y+i;
                int newX = x+1;
                if(isCellInLayout(newX,newY)){
                    if(layout[newX][newY] == State::Alive)
                        neighbors++;
                }
            }
            return neighbors;
        }

        void next_generation(){
            vector<pair<int,int>> affected_cells;
            for(int i = 0 ; i < height ; i++){
                for(int j = 0 ; j < width ; j++){
                    State state = layout[i][j];
                    int neighbors = count_neighbors(i,j);
                    if(state == State::Alive){
                        if(neighbors < 2 || neighbors > 3)
                            affected_cells.emplace_back(i,j);
                    }else{
                        if(neighbors == 3)
                            affected_cells.emplace_back(i,j);
                    }
                }
            }
            for(pair p : affected_cells){
                layout[p.first][p.second] = (layout[p.first][p.second] == State::Alive ) ? State::Dead : State::Alive;
            }
        }

        void display(){
            cout << "Turns " << turn << endl;
            for(int i = 0 ; i < height ; i++){
                for(int j = 0 ; j < width ; j++){
                    cout << (layout[i][j] == State::Alive ? "#" : "-") ;
                }
                cout << endl;
            }
        }

        void run(int turns){
            for(int i = 0 ; i < turns ; i++){
                next_generation();
                display();
            }

        }

        void toggleCell(int x , int y){
            if(isCellInLayout(x,y))
                layout[x][y] = (layout[x][y] == State::Alive) ? State::Dead : State::Alive;
        }
};

int main() {
    int width,height;
    cout << "Welcome to game of life" <<endl;
    cout << "Enter the console width and height" << endl;
    cout << "width :- ";
    cin >> width;
    cout << endl << "Height :- ";
    cin >> height;
    Universe game(width,height);

    game.initialize();
    int choose = 0;
    while(choose != -1){
        cout << "Game of life (" << width << "," << height << ")"<<endl;
        cout << "1) Display ";
        cout << "2) Reset ";
        cout << "3) Run ";
        cout << "4) Draw ";
        cout << "-1) Exit" << endl;
        cin >> choose;

        if(choose == 1){
            game.display();
        }else if(choose == 2){
            game.reset();
        }else if(choose == 3){
            int turns;
            cout << "How many turns?";
            cin >> turns;
            game.run(turns);
        }else if(choose == 4){
            int x,y;
            cout << "What is the x,y?" << endl;
            cout << "X :";cin >> x;
            cout << "Y :";cin >> y;
            game.toggleCell(x,y);
        }else if(choose == -1){
            // cout << "";
        }else{
            cout << "unknown code" << endl;
        }
    }
    return 0;
}

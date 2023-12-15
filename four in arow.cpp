#include <iostream>
#include <vector>

class FourInARowBoard {
public:
    FourInARowBoard() : rows(6), columns(7), grid(rows, std::vector<char>(columns, ' ')) {}

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cout << "| " << grid[i][j] << " ";
            }
            std::cout << "|\n";
        }
        std::cout << "-----------------------------\n";
    }

    bool makeMove(char player, int column) {
        for (int i = rows - 1; i >= 0; --i) {
            if (grid[i][column] == ' ') {
                grid[i][column] = player;
                return true;
            }
        }
        return false; // Column is full
    }

    bool isGameOver() const {
        // Implement your game over logic (e.g., check for a winner or a tie)
        return false;
    }

    bool isWinner(char i) const {
        return false;
    }

private:
    int rows;
    int columns;
    std::vector<std::vector<char>> grid;
};

class FourInARowPlayer {
public:
    FourInARowPlayer(const std::string& playerName, char playerSymbol)
            : name(playerName), symbol(playerSymbol) {}

    std::string getName() const {
        return name;
    }

    char getSymbol() const {
        return symbol;
    }

    int makeMove() const {
        int column;
        std::cout << name << ", enter your move (column 1-7): ";
        std::cin >> column;
        return column - 1; // Adjust to 0-based index
    }

private:
    std::string name;
    char symbol;
};

class FourInARowGame {
public:
    FourInARowGame(const std::string& player1Name, const std::string& player2Name)
            : board(), player1(player1Name, 'X'), player2(player2Name, 'O'), currentPlayer(&player1) {}

    void run() {
        while (!board.isGameOver()) {
            board.display();
            int column = currentPlayer->makeMove();

            while (!board.makeMove(currentPlayer->getSymbol(), column)) {
                std::cout << "Column is full. Choose another column.\n";
                column = currentPlayer->makeMove();
            }

            switchPlayer();
        }

        board.display();
        displayGameResult();
    }

private:
    FourInARowBoard board;
    FourInARowPlayer player1;
    FourInARowPlayer player2;
    FourInARowPlayer* currentPlayer;

    void switchPlayer() {
        currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
    }

    void displayGameResult() const {
        if (board.isGameOver()) {
            if (board.isWinner(player1.getSymbol())) {
                std::cout << player1.getName() << " wins!\n";
            } else if (board.isWinner(player2.getSymbol())) {
                std::cout << player2.getName() << " wins!\n";
            } else {
                std::cout << "It's a draw!\n";
            }
        }
    }
};

int main() {
    FourInARowGame game("Player 1", "Player 2");
    game.run();
    return 0;
}
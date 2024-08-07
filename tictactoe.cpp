#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const int SIZE = 3;

// Function declarations
void printBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool isBoardFull(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, int row, int col, char player);
int minimax(vector<vector<char>>& board, bool isMaximizing);
pair<int, int> findBestMove(vector<vector<char>>& board);

int main() {
    vector<vector<char>> board(SIZE, vector<char>(SIZE, EMPTY));
    char currentPlayer = PLAYER_X;
    int row, col;
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        printBoard(board);

        if (currentPlayer == PLAYER_X) {
            cout << "Player X's turn. Enter row and column (0-2): ";
            cin >> row >> col;

            if (!makeMove(board, row, col, PLAYER_X)) {
                cout << "Invalid move, try again." << endl;
                continue;
            }
        } else {
            cout << "AI's turn." << endl;
            pair<int, int> bestMove = findBestMove(board);
            row = bestMove.first;
            col = bestMove.second;
            makeMove(board, row, col, PLAYER_O);
            cout << "AI chose row " << row << " and column " << col << "." << endl;
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            if (currentPlayer == PLAYER_X) {
                cout << "Player X wins!" << endl;
            } else {
                cout << "AI wins!" << endl;
            }
            gameWon = true;
        } else if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a draw!" << endl;
            gameDraw = true;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}

void printBoard(const vector<vector<char>>& board) {
    cout << endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
        board[row][col] = player;
        return true;
    }
    return false;
}

int minimax(vector<vector<char>>& board, bool isMaximizing) {
    if (checkWin(board, PLAYER_O)) return 10;
    if (checkWin(board, PLAYER_X)) return -10;
    if (isBoardFull(board)) return 0;

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int score = minimax(board, false);
                    board[i][j] = EMPTY;
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int score = minimax(board, true);
                    board[i][j] = EMPTY;
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

pair<int, int> findBestMove(vector<vector<char>>& board) {
    int bestScore = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int score = minimax(board, false);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }

    return bestMove;
}

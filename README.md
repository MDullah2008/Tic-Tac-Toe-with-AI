# Tic Tac Toe with AI

This is a console-based Tic Tac Toe game implemented in C++ with an AI opponent. The AI uses the minimax algorithm to make optimal moves. The game supports two players: a human player (X) and an AI player (O).

## Features

- **Player vs AI**: Play against an AI that uses the minimax algorithm to make optimal moves.
- **Simple Interface**: Input moves by specifying the row and column.
- **Board Display**: The current state of the board is displayed after each move.
- **Win Detection**: The game checks for win conditions after each move.
- **Draw Detection**: The game checks for a draw when the board is full.

## How to Play

1. **Run the Program**: Compile and run the program.
2. **Player Move**: Player X enters their move by specifying the row and column (0-2).
3. **AI Move**: The AI calculates and makes its move.
4. **Game Continuation**: The game alternates between the player and AI until there is a win or draw.
5. **End Game**: The game announces the winner or a draw.

## Code Summary

### Key Functions

- `printBoard(const vector<vector<char>>& board)`: Displays the current state of the board.
- `checkWin(const vector<vector<char>>& board, char player)`: Checks if the specified player has won.
- `isBoardFull(const vector<vector<char>>& board)`: Checks if the board is full.
- `makeMove(vector<vector<char>>& board, int row, int col, char player)`: Makes a move for the specified player at the given row and column.
- `minimax(vector<vector<char>>& board, bool isMaximizing)`: Implements the minimax algorithm to evaluate the board state.
- `findBestMove(vector<vector<char>>& board)`: Determines the best move for the AI using the minimax algorithm.

## Code Structure

- The game uses a 3x3 board represented by a 2D vector of characters.
- The player and AI alternate turns, with the player starting first.
- The minimax algorithm is used by the AI to evaluate possible moves and choose the optimal one.
- The game ends when there is a win or a draw, and the result is displayed.

## Getting Started

### Prerequisites

- C++ compiler

### Compilation

Compile the program using a C++ compiler, for example:
```bash
g++ -o TicTacToe TicTacToe.cpp
```

### Running the Program

Run the compiled program:
```bash
./TicTacToe
```

## Example

```text
Player X's turn. Enter row and column (0-2): 0 0

 X
   

AI's turn.
AI chose row 1 and column 1.

 X
 O
   

Player X's turn. Enter row and column (0-2): 0 1

 X X
 O
   

AI's turn.
AI chose row 2 and column 2.

 X X
 O
   O

Player X's turn. Enter row and column (0-2): 0 2

 X X X
 O
   O

Player X wins!

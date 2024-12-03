#include <iostream>
#include <vector>
using namespace std;

#define N 8 // Size of the chessboard (N x N)

// Moves a knight can make
int knightMovesX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int knightMovesY[] = {1, 2, 2, 1, -1, -2, -2, -1};

// Utility function to check if the move is valid
bool isValidMove(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive function to solve the Knight's Tour
bool solveKnightTour(int x, int y, int moveCount, vector<vector<int>>& board) {
    // Base case: all squares are visited
    if (moveCount == N * N) {
        return true;
    }

    // Try all possible moves
    for (int i = 0; i < 8; i++) {
        int nextX = x + knightMovesX[i];
        int nextY = y + knightMovesY[i];

        if (isValidMove(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount; // Mark as visited

            if (solveKnightTour(nextX, nextY, moveCount + 1, board)) {
                return true;
            }

            // Backtrack
            board[nextX][nextY] = -1;
        }
    }

    return false;
}

// Function to start the Knight's Tour
void knightTour() {
    vector<vector<int>> board(N, vector<int>(N, -1)); // Initialize the board with -1

    // Start from the first cell
    board[0][0] = 0;

    if (solveKnightTour(0, 0, 1, board)) {
        // Print the solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists!" << endl;
    }
}

// Driver code
int main() {
    knightTour();
    return 0;
}

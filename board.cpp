#include "board.h"
using namespace std;

void Board::input() {
    cout << "Enter Sudoku:\n";

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> grid[i][j];
}

void Board::print() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << grid[i][j] << " ";

        cout << endl;
    }
}

int Board::get(int row, int col) const {
    return grid[row][col];
}

void Board::set(int row, int col, int value) {
    grid[row][col] = value;
}

bool Board::isSafe(int row, int col, int num) const {

    for (int j = 0; j < SIZE; j++)
        if (grid[row][j] == num)
            return false;

    for (int i = 0; i < SIZE; i++)
        if (grid[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

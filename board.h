#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

const int SIZE = 9;

class Board {
private:
    int grid[SIZE][SIZE];

public:
    void input();
    void print() const;

    int get(int row, int col) const;
    void set(int row, int col, int value);

    bool isSafe(int row, int col, int num) const;

    // перевірка чи всі клітинки заповнені 
    bool isFull() const;

    // отримання всіх можливих вариантів для клітинки
    std::vector<int> getCandidates(int row, int col) const;
};

#endif
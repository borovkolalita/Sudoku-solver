#ifndef BOARD_H
#define BOARD_H

#include <iostream>

const int SIZE = 9;

class Board {
private:
    int grid[SIZE][SIZE]; // поле судоку

public:
    void input();          // введення поля
    void print() const;    // вивід поля

    int get(int row, int col) const;        // отримати значення клітинки
    void set(int row, int col, int value);  // встановити значення

    bool isSafe(int row, int col, int num) const; // перевірка чи можна ставити число
};

#endif

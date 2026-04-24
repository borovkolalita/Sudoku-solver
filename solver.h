#ifndef SOLVER_H
#define SOLVER_H

#include "board.h"

// Базовий клас (інтерфейс)
class Solver {
public:
    virtual bool solve(Board& b) = 0;
    virtual ~Solver() {}
};

#endif

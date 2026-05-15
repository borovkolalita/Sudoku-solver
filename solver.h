#ifndef SOLVER_H
#define SOLVER_H

#include "board.h"

struct SolverStats {
    int recursiveCalls = 0;
    int branchesTried = 0;
};

class Solver {
public:
    SolverStats stats;

    virtual bool solve(Board& b) = 0;
    virtual ~Solver() {}
};

#endif
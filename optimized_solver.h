#ifndef OPTIMIZED_SOLVER_H
#define OPTIMIZED_SOLVER_H

#include "solver.h"

class OptimizedSolver : public Solver {
private:
    bool findBestCell(Board& b, int& bestRow, int& bestCol);

    bool propagate(Board& b);

public:
    bool solve(Board& b) override;
};

#endif
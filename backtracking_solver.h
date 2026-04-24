#ifndef BACKTRACKING_SOLVER_H
#define BACKTRACKING_SOLVER_H

#include "solver.h"

class BacktrackingSolver : public Solver {
public:
    bool solve(Board& b) override;
};

#endif

#ifndef BASELINE_SOLVER_H
#define BASELINE_SOLVER_H

#include "solver.h"

class BaselineSolver : public Solver {
public:
    bool solve(Board& b) override;
};

#endif
#ifndef NAIVE_SOLVER_H
#define NAIVE_SOLVER_H

#include "solver.h"

class NaiveSolver : public Solver {
public:
    bool solve(Board& b) override;
};

#endif

#ifndef MRV_SOLVER_H
#define MRV_SOLVER_H

#include "solver.h"

class MRVSolver : public Solver {
private:
    bool findBestCell(Board& b, int& bestRow, int& bestCol);

public:
    bool solve(Board& b) override;
};

#endif
#include "naive_solver.h"

bool NaiveSolver::solve(Board& b) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (b.get(i, j) == 0) {

                for (int num = 1; num <= 9; num++) {

                    if (b.isSafe(i, j, num)) {
                        b.set(i, j, num);
                        return solve(b);
                    }
                }

                return false;
            }
        }
    }

    return true;
}

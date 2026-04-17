#include "solver.h"

// backtracking алгоритм
bool Solver::solve(Board& b) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (b.get(i, j) == 0) {

                for (int num = 1; num <= 9; num++) {

                    if (b.isSafe(i, j, num)) {

                        b.set(i, j, num);

                        if (solve(b))
                            return true;

                        b.set(i, j, 0); // відкат
                    }
                }

                return false;
            }
        }
    }

    return true;
}

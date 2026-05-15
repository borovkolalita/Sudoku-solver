#include "baseline_solver.h"

bool BaselineSolver::solve(Board& b) {

    // рахуємо скільки разів залізли в рекурсію
    stats.recursiveCalls++;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (b.get(i, j) == 0) {

                for (int num = 1; num <= 9; num++) {

                    if (b.isSafe(i, j, num)) {

                        // рахуємо кількість спроб
                        stats.branchesTried++;

                        b.set(i, j, num);

                        if (solve(b))
                            return true;

                        b.set(i, j, 0);
                    }
                }

                return false;
            }
        }
    }

    return true;
}
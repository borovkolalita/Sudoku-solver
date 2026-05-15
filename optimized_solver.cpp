#include "optimized_solver.h"
#include <vector>

using namespace std;

bool OptimizedSolver::findBestCell(Board& b, int& bestRow, int& bestCol) {

    int minCandidates = 10;
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (b.get(i, j) == 0) {

                vector<int> candidates = b.getCandidates(i, j);

                if (candidates.empty())
                    return false;

                if (candidates.size() < minCandidates) {
                    minCandidates = candidates.size();
                    bestRow = i;
                    bestCol = j;
                    found = true;
                }
            }
        }
    }

    return found;
}

bool OptimizedSolver::propagate(Board& b) {

    bool changed;

    do {
        changed = false;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                if (b.get(i, j) == 0) {

                    vector<int> candidates = b.getCandidates(i, j);

                    // якщо кандидатів немає → помилка
                    if (candidates.empty())
                        return false;

                    // якщо лише один кандидат → ставимо значення
                    if (candidates.size() == 1) {
                        b.set(i, j, candidates[0]);
                        changed = true;
                    }
                }
            }
        }

    } while (changed);

    return true;
}

bool OptimizedSolver::solve(Board& b) {

    // рахуємо скільки разів залізли в рекурсію
    stats.recursiveCalls++;

    // спочатку propagation, а вже потім рекурсія хаос
    if (!propagate(b))
        return false;

    if (b.isFull())
        return true;

    int row, col;

    if (!findBestCell(b, row, col))
        return false;

    vector<int> candidates = b.getCandidates(row, col);

    for (int num : candidates) {

        // рахуємо кількість спроб
        stats.branchesTried++;

        // копія дошки щоб не ламати основну
        Board copy = b;

        copy.set(row, col, num);

        if (solve(copy)) {
            b = copy;
            return true;
        }
    }

    return false;
}
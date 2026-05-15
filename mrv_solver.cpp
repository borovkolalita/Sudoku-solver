#include "mrv_solver.h"
#include <vector>

using namespace std;

bool MRVSolver::findBestCell(Board& b, int& bestRow, int& bestCol) {

    int minCandidates = 10;
    bool found = false;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (b.get(i, j) == 0) {

                vector<int> candidates = b.getCandidates(i, j);

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

bool MRVSolver::solve(Board& b) {

    // рахуємо скільки разів залізли в рекурсію
    stats.recursiveCalls++;

    if (b.isFull())
        return true;

    int row, col;

    if (!findBestCell(b, row, col))
        return false;

    vector<int> candidates = b.getCandidates(row, col);

    for (int num : candidates) {

        // рахуємо кількість спроб
        stats.branchesTried++;

        b.set(row, col, num);

        if (solve(b))
            return true;

        b.set(row, col, 0);
    }

    return false;
}
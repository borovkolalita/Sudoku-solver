#include <iostream>
#include "board.h"
#include "baseline_solver.h"
#include "mrv_solver.h"
#include "optimized_solver.h"

using namespace std;

int main() {

    Board board;

    cout << "Choose solver:\n";
    cout << "1 - Baseline Solver\n";
    cout << "2 - MRV Solver\n";
    cout << "3 - Optimized Solver (MRV + Propagation)\n";

    int choice;
    cin >> choice;

    Solver* solver = nullptr;

    if (choice == 1)
        solver = new BaselineSolver();

    else if (choice == 2)
        solver = new MRVSolver();

    else
        solver = new OptimizedSolver();

    board.input();

    cout << "\nInitial board:\n";
    board.print();

    if (solver->solve(board)) {

        cout << "\nSolved Sudoku:\n";
        board.print();

        cout << "\nStatistics:\n";
        cout << "Recursive calls: "
             << solver->stats.recursiveCalls << endl;

        cout << "Branches tried: "
             << solver->stats.branchesTried << endl;
    }
    else {
        cout << "No solution found\n";
    }

    delete solver;

    return 0;
}
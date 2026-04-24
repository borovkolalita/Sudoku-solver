#include <iostream>
#include "board.h"
#include "backtracking_solver.h"
#include "naive_solver.h"

using namespace std;

int main() {
    Board b;

    Solver* solver = nullptr;

    int choice;
    cout << "Choose solver:\n";
    cout << "1 - Backtracking Solver\n";
    cout << "2 - Naive Solver\n";
    cin >> choice;

    if (choice == 1)
        solver = new BacktrackingSolver();
    else
        solver = new NaiveSolver();

    b.input();

    cout << "\nInitial board:\n";
    b.print();

    if (solver->solve(b)) {
        cout << "\nSolved Sudoku:\n";
        b.print();
    } else {
        cout << "No solution found\n";
    }

    delete solver;

    return 0;
}

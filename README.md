# Sudoku Solver Optimization (Lab 07)
## Description
This project implements an optimized Sudoku solver using object-oriented programming. The goal of this version is to improve search efficiency using heuristics and constraint propagation.

## Structure
Board class — manages the 9x9 grid, candidate generation, and validation.

Solver (Interface) — abstract base class for different solving strategies.

BaselineSolver — standard backtracking (for performance comparison).

MRVSolver — implements the Minimum Remaining Values heuristic.

OptimizedSolver — combines MRV with Iterative Constraint Propagation (forced moves).

## Features
Heuristic search: Selects cells with the fewest possible candidates to reduce branching.

Constraint Propagation: Automatically fills "forced" cells before starting recursion.

Performance Tracking: Collects statistics on recursive calls and attempted branches to compare solver efficiency.

Extensible Architecture: Uses inheritance and polymorphism to switch between different solver algorithms.

## How to run
### Compile all source files:

Bash
g++ main.cpp board.cpp baseline_solver.cpp mrv_solver.cpp optimized_solver.cpp -o sudoku
Run:

Bash
./sudoku
Choose the solver type in the menu and enter a 9x9 Sudoku grid (use 0 for empty cells).

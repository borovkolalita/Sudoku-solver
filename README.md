## Sudoku Solver 

### Description  
This project implements a Sudoku solver using object-oriented programming, composition, and polymorphism.  
Different solving strategies can be used via a common interface.

### Structure  
- **Board** — represents the Sudoku grid  
- **Solver (abstract class)** — base interface for solving  
- **BacktrackingSolver** — main solving algorithm  
- **NaiveSolver** — simple demo solver (for polymorphism)

### How to run  
Compile:
```bash
g++ main.cpp board.cpp backtracking_solver.cpp random_solver.cpp -o sudoku
```

Run:
```bash
./sudoku
```

Enter a 9×9 Sudoku grid (use `0` for empty cells)

### Features  
- Sudoku input/output  
- Board validation  
- Backtracking solving algorithm  
- Demonstration of polymorphism  

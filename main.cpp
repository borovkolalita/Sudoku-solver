#include <iostream>
#include "board.h"
#include "solver.h"

using namespace std;

int main() {
    Board b;
    Solver s;

    b.input();

    cout << "\nПочаткове поле:\n";
    b.print();

    if (s.solve(b)) {
        cout << "\nРозв'язок:\n";
        b.print();
    } else {
        cout << "Рішення не знайдено\n";
    }

    return 0;
}

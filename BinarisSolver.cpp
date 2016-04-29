
#include <BinarisSolver.h>
#include <iostream>
using namespace std;

BinarisSolver::BinarisSolver(){
    set_grid_size();
    clear_grid();
    read();
}

BinarisSolver::~BinarisSolver(){
    for(int i = 0; i < n; ++i) {
        delete [] grid[i];
    }
    delete [] grid;
}

void BinarisSolver::set_grid_size(){
    do {
        cout << "Enter the grid size: ";
        cin >> n;
        cout << endl;

        /* sanitize */
        if(n <= 0){
            cout << "Positive integers only." << endl << endl;
            continue;
        } else if (n % 2){
            cout << "Even numbers only." << endl << endl;
            continue;
        } else {
            break;
        }
    } while (true);
    cin.get(); //clear extra newline from stream

    /* allocate grid space */
    grid = new int*[n];
    for(int i = 0; i < n; i++){
        grid[i] = new int[n];
    }
}

void BinarisSolver::clear_grid(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = BLANK;
        }
    }
}

/*
 * Note that any character other than a 1 or 0 is interpreted as a blank space.
 * PRECONDITIONS: n is set, grid space is allocated
 */
void BinarisSolver::read(){
    cout << "Enter the values for each row: use 1/0 for occupied, and spaces for unoccupied." << endl << endl;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; ; j++){
            cin.get(c);
            if(c == '\n' || j == n) break;
            else if(c == '0')
                grid[i][j] = 0;
            else if(c == '1')
                grid[i][j] = 1;
        }
    }
}





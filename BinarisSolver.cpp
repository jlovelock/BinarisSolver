
#include <BinarisSolver.h>
#include <iostream>
using namespace std;

BinarisSolver::BinarisSolver(){
    set_grid_size();
    grid = new Grid(n);
}

BinarisSolver::~BinarisSolver(){
    delete grid;
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
}

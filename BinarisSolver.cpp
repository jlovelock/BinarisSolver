
#include <BinarisSolver.h>
#include <iostream>
using namespace std;

BinarisSolver::BinarisSolver(){
    original = new Grid();
    grid = new Grid(original);
}

BinarisSolver::~BinarisSolver(){
    delete original;
    delete grid;
}


void BinarisSolver::solve(){
    bool found;
    do {
        found = false;
        found = found | check_all_max_copies();
    } while( !grid->full() && found );

    if(grid->full()){
        cout << "Puzzle solved!" << endl << endl;
    } else {
        cout << "Unable to fully solve puzzle." << endl << endl;
    }

    grid->print();

}

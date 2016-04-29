
#include <BinarisSolver.h>
#include <iostream>
using namespace std;

BinarisSolver::BinarisSolver(){
    original = new Grid();
    grid = new Grid(original);
    moves.clear();
}

BinarisSolver::~BinarisSolver(){
    delete original;
    delete grid;
    moves.clear();
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
    print_log();
    grid->print();

}


void BinarisSolver::print_log(){
    for(auto it = moves.begin(); it != moves.end(); ++it){
        cout << it->description() << endl;
    }
    cout << endl;
}

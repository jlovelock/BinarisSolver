
#include <BinarisSolver.h>
#include <iostream>
#include <stdexcept>
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
        try {
            found = false;
            found = found | check_all_pairs();
            found = found | check_all_max_copies();
        }
        catch (invalid_argument e) {
            cout << "Invalid grid provided: " << e.what() << endl;
            print_log();
            cout << "Grid at final step:" << endl;
            grid->print();
            return;
        }
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
    cout << "Solution log:" << endl;
    for(auto it = moves.begin(); it != moves.end(); ++it){
        cout << it->description() << endl;
    }
    cout << endl;
}

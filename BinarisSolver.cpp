
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
            break;
        }
    } while( !grid->full() && found );
    cleanup();
}

void BinarisSolver::cleanup(){
    if(grid->full()){
        cout << "Puzzle solved!" << endl << endl;
    } else {
        cout << "Unable to fully solve puzzle." <<  endl << endl;
        cout << "Grid at final state: " << endl;
    }

    grid->print();
    cout << endl << "Print solution log? (y/n) ";
    char input;
    cin >> input;
    if (input == 'y') print_log();
}
void BinarisSolver::print_log(){
    if(moves.empty()){
        cout << "No solution steps to display." << endl;
    } else {
        for(auto it = moves.begin(); it != moves.end(); ++it){
            cout << it->description() << endl;
        }
    }
    cout << endl;
}

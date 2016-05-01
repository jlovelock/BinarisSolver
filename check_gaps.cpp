
#include <BinarisSolver.h>
#include <defines.h>
#include <stdexcept>
#include <iostream>
#include <move.h>
using namespace std;


/**
 ** Logic for this file's subroutines:
 **
 ** Three or more ones and zeros must never be adjacent across a row or column.
 ** Therefore, if you find two of the same number along a line separated by a single blank space,
 **   that blank space must be filled with the opposite number.
 ** (Otherwise, it would end up as three-in-a-row, which is illegal.)
 **/

bool BinarisSolver::check_all_gaps(){
    bool found = false;
    for(int i = 0; i < grid->size()-2; i++ ) { /* stop 2 early to ensure each triplet you're checking stays w/in bounds */
        for(int j = 0; j < grid->size(); j++){
            found = found | check_gap( make_pair(i, j), false );   /* columns */
            found = found | check_gap( make_pair(j, i), true );    /* rows */
        }
    }
    return found;
}


bool BinarisSolver::check_gap(pair<int,int> coord, bool is_row){
    /* 1. Get value at starting square */
    int initial_value = grid->at(coord);
    if( initial_value == BLANK ) return false;

    /* 2. Next square should be blank */
    pair<int,int> dir = ( is_row ? make_pair(0,1) : make_pair(1,0) );
    advance(coord, dir);
    if ( grid->at(coord) != BLANK ) return false;

    /* 3. Final square should have same value as initial */
    /*    If so, pair found: rewind to the blank square and update! */
    advance (coord, dir);
    if ( grid->at(coord) == initial_value ) {
        advance(coord, dir, -1);
        grid->set(coord, !initial_value);
        moves.push_back( FoundGapMove(coord, !initial_value, is_row) );
        return true;
    }
    return false;
}

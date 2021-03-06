
#include <BinarisSolver.h>
#include <defines.h>
#include <stdexcept>
#include <iostream>
#include <move.h>
using namespace std;


/**
 ** Logic for this file's subroutines:
 **
 ** Each row and column for a valid solution contains an equal number of ones and zeros.
 ** Therefore, the maximum number of each is easily calculated (as half the row/col size).
 ** If any given row or column already has the maximum number of allowable ones/zeroes,
 **   all remaining blanks in that row must be filled with the opposite number.
 **/


/*
 * Returns true if at least one row/col was updated via this logic
 */
bool BinarisSolver::check_all_max_copies(){
    bool found = false;
    for(int i = 0; i < grid->size(); i++){
        found = found | counter(i, true);
        found = found | counter(i, false);
    }
    return found;
}

/*
 * Eg. num=2, is_row=false, checks column 2
 * Checks how many ones/zeroes are in that line
 * If that's equal to the max possible, fills the rest of that line's BLANKs with the opposite
 * Returns true if any cells were updated
 */
bool BinarisSolver::counter(int num, bool is_row){
    pair<int,int> coord = ( is_row ? make_pair(num, 0) : make_pair(0, num) );
    pair<int,int> dir   = ( is_row ? make_pair(0, 1)   : make_pair(1, 0)   );
    int zeros = 0, ones = 0;

    for( ; !grid->out_of_bounds(coord); advance(coord, dir) ){
        switch( grid->at(coord) ){
            case 0: zeros++; break;
            case 1: ones++;  break;
        }
    }

    if(zeros > max_copies())
        throw invalid_argument("Too many zeros per line");
    else if (ones > max_copies())
        throw invalid_argument("Too many ones per line");

    if(zeros == max_copies() && ones < max_copies()){
        fill_blanks(num, is_row, 1);
        return true;
    } else if(zeros < max_copies() && ones == max_copies()){
        fill_blanks(num, is_row, 0);
        return true;
    }
    return false;
}


void BinarisSolver::fill_blanks(int num, bool is_row, int fill_with){
    pair<int,int> coord = ( is_row ? make_pair(num, 0) : make_pair(0, num) );
    pair<int,int> dir   = ( is_row ? make_pair(0, 1)   : make_pair(1, 0)   );

    for( ; !grid->out_of_bounds(coord); advance(coord, dir) ){
        if( grid->at(coord) == BLANK ){
            grid->set(coord, fill_with);
            moves.push_back( MaxCopiesMove(coord, fill_with, is_row) );
        }
    }
}


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
 ** Therefore, if two are already adjacent, they must be surrounded by the opposite number.
 **/


bool BinarisSolver::check_all_pairs(){
    bool found = false;
    for(int i = 0; i < grid->size()-1; i++ ) { /* stop 1 early to ensure each pair you're checking is w/in bounds */
        for(int j = 0; j < grid->size(); j++){
            found = found | check_pair( make_pair(i,                j), make_pair( 1,  0) );   /* down */
            found = found | check_pair( make_pair(grid->size()-i-1, j), make_pair(-1,  0) );   /* up */
            found = found | check_pair( make_pair(j,                i), make_pair( 0,  1) );   /* right */
            found = found | check_pair( make_pair(j, grid->size()-i-1), make_pair( 0, -1) );   /* left */
        }
    }
    return found;
}

bool BinarisSolver::check_pair(pair<int,int> coord, pair<int,int> dir){
    int val = grid->at(coord);
    if( val == BLANK ) return false;
    advance(coord, dir);
    if (val == grid->at(coord)){
        advance(coord, dir);
        if( !grid->out_of_bounds(coord) ){
            if( grid->at(coord) == val )
                throw invalid_argument("too many adjacent values");
            else if(grid->at(coord) == BLANK) {
                grid->set(coord, !val);
                moves.push_back( FoundPairMove(coord, !val, dir) );
                return true;
            }
        }
    }
    return false;
}

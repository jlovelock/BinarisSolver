
#include <BinarisSolver.h>
#include <iostream>
#include <utility>
using namespace std;



void BinarisSolver::advance(pair<int,int>& coords, pair<int,int>& direction){
    coords.first += direction.first;
    coords.second += direction.second;
}

/*
 * The max number of ones/zeros that can appear in any given row/column
 */
int BinarisSolver::max_copies(){
    return grid->size()/2;
}

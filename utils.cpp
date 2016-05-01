
#include <BinarisSolver.h>
#include <iostream>
#include <utility>
#include <sstream>
using namespace std;



void advance(pair<int,int>& coords, pair<int,int> direction, int n_steps){
    coords.first += direction.first * n_steps;
    coords.second += direction.second * n_steps;
}

/*
 * The max number of ones/zeros that can appear in any given row/column
 */
int BinarisSolver::max_copies(){
    return grid->size()/2;
}

string str(pair<int,int> coord){
    stringstream ss;
    ss << "(" << coord.first << "," << coord.second << ")";
    return ss.str();
}

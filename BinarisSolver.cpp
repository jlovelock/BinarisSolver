
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



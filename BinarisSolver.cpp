
#include <BinarisSolver.h>
#include <iostream>
using namespace std;

BinarisSolver::BinarisSolver(){
    grid = new Grid();
}

BinarisSolver::~BinarisSolver(){
    delete grid;
}



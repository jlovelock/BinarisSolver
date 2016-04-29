
#ifndef BINARIS_SOLVER_H
#define BINARIS_SOLVER_H

#include <grid.h>
#include <utility>

class BinarisSolver {

public:
    BinarisSolver();
    ~BinarisSolver();
    Grid* grid;

private:
    int n;

    void set_grid_size();
    void advance(std::pair<int,int>& coords, std::pair<int,int>& direction);

};

#endif // BINARIS_SOLVER_H

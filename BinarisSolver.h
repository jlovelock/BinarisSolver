
#ifndef BINARIS_SOLVER_H
#define BINARIS_SOLVER_H

#include <grid.h>
#include <utility>

class BinarisSolver {

public:
    BinarisSolver();
    ~BinarisSolver();
    Grid *grid, *original;
    void solve();


private:
    void advance(std::pair<int,int>& coords, std::pair<int,int>& direction);
    void fill_blanks(int num, bool is_row, int fill_with);

    /* check_quantities.cpp */
    bool check_all_max_copies();
    int max_copies();
    bool counter(int num, bool is_row);

};

#endif // BINARIS_SOLVER_H

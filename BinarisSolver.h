
#ifndef BINARIS_SOLVER_H
#define BINARIS_SOLVER_H

#include <grid.h>
#include <utility>

class BinarisSolver {

public:
    BinarisSolver();
    ~BinarisSolver();
    Grid *grid, *original;
    void check_all_max_copies();

private:
    void advance(std::pair<int,int>& coords, std::pair<int,int>& direction);
    void fill_blanks(int num, bool is_row, int fill_with);

    int max_copies();
    void counter(int num, bool is_row);

};

#endif // BINARIS_SOLVER_H

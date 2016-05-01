
#ifndef BINARIS_SOLVER_H
#define BINARIS_SOLVER_H

#include <grid.h>
#include <move.h>
#include <utility>
#include <vector>

class BinarisSolver {

public:
    BinarisSolver();
    ~BinarisSolver();
    void solve();
    void print_log();

private:
    std::vector<Move> moves; /* step-by-step solution logging */

    Grid *grid, *original;

    /* check_quantities.cpp */
    bool check_all_max_copies();
    int max_copies();
    bool counter(int num, bool is_row);
    void fill_blanks(int num, bool is_row, int fill_with);

    /* check_pairs.cpp */
    bool check_all_pairs();
    bool check_pair(std::pair<int,int>, std::pair<int,int>);
};

#endif // BINARIS_SOLVER_H

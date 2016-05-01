
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
    Grid *grid, *original;
    std::vector<Move> moves; /* step-by-step solution logging */
    void cleanup();

    /* check_quantities.cpp */
    bool check_all_max_copies();
    int max_copies();
    bool counter(int num, bool is_row);
    void fill_blanks(int num, bool is_row, int fill_with);

    /* check_pairs.cpp */
    bool check_all_pairs();
    bool check_pair(std::pair<int,int> coord, std::pair<int,int> dir);

    /* check_gaps.cpp */
    bool check_all_gaps();
    bool check_gap(std::pair<int,int> coord, bool is_row);
};

#endif // BINARIS_SOLVER_H

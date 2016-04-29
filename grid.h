
#ifndef GRID_H
#define GRID_H

#include <utility>

class Grid {
public:
    Grid(int);
    ~Grid();

    void read();
    void print();
    int at(std::pair<int,int>);

    bool out_of_bounds(std::pair<int,int> coords);

private:
    int** vals;
    int n;

    void clear_grid();
};

#endif // GRID_H

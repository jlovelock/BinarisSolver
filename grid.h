
#ifndef GRID_H
#define GRID_H

#include <utility>

class Grid {
public:
    Grid();
    Grid(Grid*);
    ~Grid();

    void read();
    void print();
    int at(std::pair<int,int>);
    void set(std::pair<int,int>, int val);

    bool out_of_bounds(std::pair<int,int> coords);
    int size(){ return n; }
    bool full();

private:
    int** vals;

    int n;
    void set_grid_size();

    void clear_grid();
};

#endif // GRID_H

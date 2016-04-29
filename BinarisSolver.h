
#include <utility>
#define BLANK -10

class BinarisSolver {

public:
    BinarisSolver();
    ~BinarisSolver();

    void read();
    void print_grid();

private:
    int** grid;
    int n;

    void set_grid_size();
    void clear_grid();

    void advance(std::pair<int,int>& coords, std::pair<int,int>& direction);
    bool out_of_bounds(std::pair<int,int> coords);

};

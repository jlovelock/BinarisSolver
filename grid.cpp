
#include <grid.h>
#include <stdexcept>
#include <defines.h>
#include <iostream>
using namespace std;

Grid::Grid(){
    /* allocate space */
    set_grid_size();
    vals = new int*[n];
    for(int i = 0; i < n; i++){
        vals[i] = new int[n];
    }
    /* set initial values */
    clear_grid();
    read();
}

Grid::Grid(Grid* g){
    /* allocate space */
    n = g->n;
    vals = new int*[n];
    for(int i = 0; i < n; i++){
        vals[i] = new int[n];
    }
    /* set initial values */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vals[i][j] = g->vals[i][j];
        }
    }
}

Grid::~Grid(){
    for(int i = 0; i < n; ++i) {
        delete [] vals[i];
    }
    delete [] vals;
}

void Grid::set_grid_size(){
    do {
        cout << "Enter the grid size: ";
        cin >> n;
        cout << endl;

        /* sanitize */
        if(n <= 0){
            cout << "Positive integers only." << endl << endl;
            continue;
        } else if (n % 2){
            cout << "Even numbers only." << endl << endl;
            continue;
        } else {
            break;
        }
    } while (true);
    cin.get(); //clear extra newline from stream
}



void Grid::print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vals[i][j] == BLANK)
                cout << ' ';
            else
                cout << vals[i][j];
        }
        cout << endl;
    }
}

void Grid::clear_grid(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vals[i][j] = BLANK;
        }
    }
}

/*
 * Note that any character other than a 1 or 0 is interpreted as a blank space.
 * PRECONDITIONS: n is set, grid space is allocated
 */
void Grid::read(){
    cout << "Enter the values for each row: use 1/0 for occupied, and spaces for unoccupied." << endl << endl;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; ; j++){
            cin.get(c);
            if(c == '\n' || j == n) break;
            else if(c == '0')
                vals[i][j] = 0;
            else if(c == '1')
                vals[i][j] = 1;
        }
    }
}

int Grid::at(pair<int,int> coord){
    if(out_of_bounds(coord))
        throw std::out_of_range("Illegal coordinate access in Grid::at.");

    return vals[coord.first][coord.second];
}

void Grid::set(pair<int,int> coord, int val){
    if(out_of_bounds(coord))
        throw std::out_of_range("Illegal coordinate access in Grid::set.");

    /* Sanity: any input other than 0/1 interpreted as blank. */
    if(val != 0 && val != 1)
        val = BLANK;

    vals[coord.first][coord.second] = val;
}

bool Grid::out_of_bounds(pair<int,int> coords){
    return
        coords.first < 0 ||
        coords.first >= n ||
        coords.second < 0 ||
        coords.second >= n;
}


#include <BinarisSolver.h>
#include <iostream>
#include <utility>
using namespace std;


void BinarisSolver::print_grid(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == BLANK)
                cout << ' ';
            else
                cout << grid[i][j];
        }
        cout << endl;
    }
}

bool BinarisSolver::out_of_bounds(pair<int,int> coords){
    return
        coords.first < 0 ||
        coords.first >= n ||
        coords.second < 0 ||
        coords.second >= n;
}

void BinarisSolver::advance(pair<int,int>& coords, pair<int,int>& direction){
    coords.first += direction.first;
    coords.second += direction.second;
}

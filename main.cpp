
#include <BinarisSolver.h>
#include <move.h>
#include <utility>
#include <iostream>
using namespace std;


int main(){
    char input;
    do {
        BinarisSolver b;
        b.solve();
        cout << "Enter another puzzle? (y/n) ";
        cin >> input;
        cout << endl;
    } while(input == 'y');
    return 0;
}


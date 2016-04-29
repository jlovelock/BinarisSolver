
#include <move.h>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


Move::Move(pair<int,int> c, int v, string d){
    coord = c;
    value = v;
    desc = d;

    stringstream ss;
    ss << value << " @ (" << coord.first << "," << coord.second << "): "
       << d;
    desc = ss.str();
}

MaxCopiesMove::MaxCopiesMove(pair<int,int> c, int v, bool row) : Move(c, v, ""){
    is_row = row;

    stringstream ss;
    ss << value << " @ (" << coord.first << "," << coord.second << "): "
       << "max " << !value << "'s in " << ( is_row ? "row " : "col " ) << ( is_row ? coord.first : coord.second );
    desc = ss.str();
}

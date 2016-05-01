
#include <move.h>
#include <defines.h>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


Move::Move(pair<int,int> c, int v, string d){
    coord = c;
    value = v;
    desc = d;
}

string Move::description() {
    stringstream ss;
    ss << value << " @ (" << coord.first << "," << coord.second << ")";
    if(desc != "")
        ss << ": " << desc;
    return ss.str();
}

MaxCopiesMove::MaxCopiesMove(pair<int,int> c, int v, bool row) : Move(c, v){
    is_row = row;

    stringstream ss;
    ss << "max " << !value << "'s in " << ( is_row ? "row " : "col " ) << ( is_row ? coord.first : coord.second );
    desc = ss.str();
}

FoundPairMove::FoundPairMove(pair<int,int> c, int v, pair<int,int> d) : Move(c, v){
    dir = d;
    dir.first *= -1;  /* got to this coord by coming from dir, so this pair is the opposite way */
    dir.second *= -1;

    stringstream ss;
    ss << "pair of " << !v << "'s found at ";
    pair<int,int> tmp = c;
    advance(tmp, dir);
    ss << str(tmp) << " and ";
    advance(tmp, dir);
    ss << str(tmp);
    desc = ss.str();
}

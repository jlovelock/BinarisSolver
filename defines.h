
#ifndef DEFINES_H
#define DEFINES_H

#include <utility>
#include <string>

#define BLANK -10
std::string str(std::pair<int,int>);
void advance(std::pair<int,int>& coords, std::pair<int,int> direction, int n_steps=1);

#endif // DEFINES_H

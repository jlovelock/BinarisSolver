#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <utility>

class Move {
    public:
        Move(std::pair<int,int>, int, std::string);
        virtual ~Move() {}
        std::string description() { return desc; }

    protected:
        int value;
        std::pair<int,int> coord;
        std::string desc;
};


class MaxCopiesMove : public Move {
    public:
        MaxCopiesMove(std::pair<int,int>, int, bool);
    private:
        bool is_row;

};


#endif // MOVE_H


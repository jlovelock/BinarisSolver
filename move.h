#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <utility>

/**
 ** Yes, these classes are storing way more values than necessary right now.
 ** I could just have functions that return a customized string description of the move.
 ** HOWEVER. In the long run, it'd be nice to have a better-displayed visual move history.
 ** Saving stuff like this will allow for easier highlighting of specific cells/rows/columns, eg.
 **/


class Move {
    public:
        Move(std::pair<int,int>, int, std::string d="");
        virtual ~Move() {}
        std::string description();

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

class FoundPairMove : public Move {
    public:
        FoundPairMove(std::pair<int,int>, int, std::pair<int,int>);
    private:
        std::pair<int,int> dir;


};

class FoundGapMove : public Move {
    public:
        FoundGapMove(std::pair<int,int>, int, bool);
    private:
        bool is_row;
};

#endif // MOVE_H


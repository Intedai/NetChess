#pragma once

#include <iostream>
#include "board.hpp"

class Chess {
    private:
        Board board;
    public:
    Chess() : board(){}
    void run();
};
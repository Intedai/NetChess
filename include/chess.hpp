#pragma once

#include <iostream>
#include "board.hpp"

class Chess {
    private:
        Board board;
        Color currentPlayer;

        void changePlayer();
    public:
        Chess() : board(), currentPlayer(Color::white) {}
        void run();
};
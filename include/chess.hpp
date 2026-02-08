#pragma once

#include <iostream>
#include <string_view>
#include <cctype>
#include "board.hpp"

class Chess {
    private:
        Board board;
        Color currentPlayer;

        void changePlayer();
    public:
        Chess();
        void run();
};
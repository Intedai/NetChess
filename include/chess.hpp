#pragma once

#include <iostream>
#include <string_view>
#include <cctype>
#include <optional>
#include "board.hpp"

class Chess {
    private:
        Board board;
        Color currentPlayer;

        void changePlayer();
        bool validateInput(std::string_view svInput, int& row, int& col);
    public:
        Chess();
        void run();
};
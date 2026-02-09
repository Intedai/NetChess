#pragma once

#include <string>
#include "color.hpp"

class Board;

class Piece {
    protected:
        Color color;
    public:
        explicit Piece(Color color) : color(color) {}
        virtual ~Piece() = default;
        Color getColor() const {return color;}
        virtual std::string getSymbol() const = 0;
        virtual bool isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const = 0;
};

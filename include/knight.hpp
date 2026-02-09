#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"

class Board;

class Knight : public Piece {
    public:
        explicit Knight(Color color) : Piece(color) {}
        std::string getSymbol() const override;
        bool isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
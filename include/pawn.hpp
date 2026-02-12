#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"
#include "validation.hpp"
#include "board.hpp"

class Pawn : public Piece {
    public:
        explicit Pawn(Color color) : Piece(color) {}
        std::string getSymbol() const override;
        bool isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
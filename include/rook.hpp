#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "tracked_piece.hpp"
#include "validation.hpp"
#include "board.hpp"

class Rook : public TrackedPiece {
    public:
        explicit Rook(Color color) : TrackedPiece(color) {}
        std::string getSymbol() const override;
        bool isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
#pragma once

#include <string>
#include <cstdlib>
#include "color.hpp"
#include "square.hpp"
#include "tracked_piece.hpp"
#include "validation.hpp"
#include "board.hpp"

class King : public TrackedPiece {
    public:
        explicit King(Color color) : TrackedPiece(color) {}
        std::string getSymbol() const override;
        bool isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
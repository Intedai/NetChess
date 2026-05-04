#pragma once

#include <string>
#include <cstdlib>
#include "color.hpp"
#include "square.hpp"
#include "tracked_piece.hpp"
#include "validation.hpp"
#include "board.hpp"

class Pawn : public TrackedPiece {
    private:
        int direction;
    public:
        explicit Pawn(Color color);
        std::string getSymbol() const override;
        bool isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
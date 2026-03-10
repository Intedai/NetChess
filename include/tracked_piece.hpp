#pragma once

#include "piece.hpp"

class TrackedPiece : public Piece {
    protected:
        bool moved;
    public:
        explicit TrackedPiece(Color color) : Piece(color), moved(false) {}
        void onMove() override;
};
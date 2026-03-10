#include "tracked_piece.hpp"

void TrackedPiece::onMove() {
    if (!moved)
        moved = true;
}
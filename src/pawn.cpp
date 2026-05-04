#include "pawn.hpp"

Pawn::Pawn(Color color) : TrackedPiece(color) {
    direction = color == Color::white ? 1 : - 1;
}

std::string Pawn::getSymbol() const {
    return color == Color::white ? "♙" : "♟";
}

bool Pawn::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    if (!Validation::isInBoard(toRow, toCol))
        return false;

    std::optional<Color> toColor = board.getPieceColor(toRow, toCol);
    
    // Check if either going forward once (or twice in first time, which i can check because it's a trackedpiece)
    // or if eating, and if not return false

    return true;
}
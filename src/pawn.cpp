#include "pawn.hpp"

std::string Pawn::getSymbol() const {
    return color == Color::white ? "♙" : "♟";
}

bool Pawn::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return true;
}
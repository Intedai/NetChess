#include "king.hpp"

std::string King::getSymbol() const {
    return color == Color::white ? "♔" : "♚";
}

bool King::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return true;
}
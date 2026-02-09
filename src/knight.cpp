#include "knight.hpp"

std::string Knight::getSymbol() const {
    return color == Color::white ? "♘" : "♞";
}

bool Knight::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return true;
}
#include "rook.hpp"

std::string Rook::getSymbol() const {
    return color == Color::white ? "♖" : "♜";
}

bool Rook::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return true;
}
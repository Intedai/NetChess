#include "bishop.hpp"

std::string Bishop::getSymbol() const {
    return color == Color::white ? "♗" : "♝";
}

bool Bishop::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return Validation::isValidDiagonalMove(board, fromRow, fromCol, toRow, toCol);
}
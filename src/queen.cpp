#include "queen.hpp"

std::string Queen::getSymbol() const {
    return color == Color::white ? "♕" : "♛";
}

bool Queen::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return (
        Validation::isValidStraightMove(board, fromRow, fromCol, toRow, toCol) ||
        Validation::isValidDiagonalMove(board, fromRow, fromCol, toRow, toCol)
    );
}
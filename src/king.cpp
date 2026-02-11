#include "king.hpp"

std::string King::getSymbol() const {
    return color == Color::white ? "♔" : "♚";
}

bool King::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    return (
        Validation::isInBoard(toRow, toCol) &&
        *(board.getPieceColor(toRow, toCol)) != color &&
        std::abs(fromRow - toRow) <= 1 && std::abs(fromCol - toCol) <=1 
    );
}
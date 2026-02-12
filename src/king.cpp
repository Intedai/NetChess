#include "king.hpp"

std::string King::getSymbol() const {
    return color == Color::white ? "♔" : "♚";
}

bool King::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {
    if (!Validation::isInBoard(toRow, toCol))
        return false;

    std::optional<Color> toColor = board.getPieceColor(toRow, toCol);

    if (toColor.has_value() && color == *toColor)
        return false;
   
    return std::abs(fromRow - toRow) <= 1 && std::abs(fromCol - toCol) <= 1;
}
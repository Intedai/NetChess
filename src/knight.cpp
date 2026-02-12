#include "knight.hpp"

std::string Knight::getSymbol() const {
    return color == Color::white ? "♘" : "♞";
}

bool Knight::isValidMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) const {

    if (
        !Validation::isInBoard(toRow, toCol) ||
        *(board.getPieceColor(toRow, toCol)) == color
    )
        return false;

    int rowDist = std::abs(fromRow - toRow);
    int colDist = std::abs(fromCol - toCol);

    return (
        (rowDist == 2 && colDist == 1) ||
        (rowDist == 1 && colDist == 2)
    );
}
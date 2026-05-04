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
    
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;
    
    if (rowDiff == 0)
        return false;
    
    int rowDist = abs(rowDiff);
    int colDist = abs(colDiff);

    int rowDirection = rowDiff / rowDist;
    
    if (rowDirection != direction)
        return false;
    
    // Moves straight 1 or 2 squares vertically without capturing 
    if (
        !toColor.has_value() &&
        colDist == 0 &&
        (rowDist == 1 || (
            !moved &&
            rowDist == 2 &&
            // Make sure it doesn't pass through a piece
            !board.getPieceColor(fromRow + direction, toCol).has_value()
        ))
    )
        return true;
    // Capturing
    else if (
        toColor.has_value() &&
        rowDist == 1 &&
        colDist == 1 &&
        color != *toColor
    )
        return true;
    return false;
}
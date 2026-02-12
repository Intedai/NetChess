#include "board.hpp"
#include "validation.hpp"

bool Validation::isInBoard(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE; 
}

bool Validation::isValidStraightMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) {
    if (!Validation::isInBoard(toRow, toCol))
        return false;
    
    bool is_vertical = fromCol == toCol;
    bool is_horizontal = fromRow == toRow;

    if (!((is_horizontal && !is_vertical) || (!is_horizontal && is_vertical)))
        return false;

    std::optional<Color> fromColor = board.getPieceColor(fromRow, fromCol);
    std::optional<Color> toColor = board.getPieceColor(toRow, toCol);

    if (!fromColor || toColor.has_value() && *fromColor == *toColor)
        return false;

    int idx;
    int destIdx;
    int inc;

    if (is_horizontal) {
        idx = fromCol;
        destIdx = toCol;
    }
    else
    {
        idx = fromRow;
        destIdx = toRow;
    }

    if (destIdx > idx)
        inc = 1;
    else
        inc = -1;

    idx += inc;
    while (idx != destIdx)
    {
        if (is_horizontal) {
            if (board.getPieceColor(fromRow, idx).has_value())
                return false;
        }
        else {
            if (board.getPieceColor(idx, fromCol).has_value())
                return false;
        }
        
        idx += inc;
    }
    
    return true;
}

bool Validation::isValidDiagonalMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) {
    return true;
}
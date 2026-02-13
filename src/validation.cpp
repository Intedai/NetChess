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
    if (!Validation::isInBoard(toRow, toCol))
        return false;
    
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    int rowDist = std::abs(rowDiff);
    int colDist = std::abs(colDiff);

    if (rowDist != colDist)
        return false;

    std::optional<Color> fromColor = board.getPieceColor(fromRow, fromCol);
    std::optional<Color> toColor = board.getPieceColor(toRow, toCol);

    if (!fromColor || toColor.has_value() && *fromColor == *toColor)
        return false;
    
    /*Avoiding big if statement by getting the increment from diving the differnce by the distance
    esentially getting 1 with the corrent sign*/
    int rowInc = rowDiff / rowDist;
    int colInc = colDiff / colDist;
    int rowIdx = fromRow + rowInc;
    int colIdx = fromCol + colInc;

    while(rowIdx != toRow /*&& colIdx != toRow (checking 1 is enough)*/) {
        if (board.getPieceColor(rowIdx, colIdx).has_value())
            return false;

        rowIdx += rowInc;
        colIdx += colInc;
    }

    return true;
}
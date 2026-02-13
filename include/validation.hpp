#include <cstdlib>
#include <optional>

class Board;

namespace Validation {
    bool isInBoard(int row, int col);
    bool isValidStraightMove(Board& board, int fromRow, int fromCol, int toRow, int toCol);
    bool isValidDiagonalMove(Board& board, int fromRow, int fromCol, int toRow, int toCol);
}


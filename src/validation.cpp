#include "board.hpp"
#include "validation.hpp"

bool Validation::isInBoard(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE; 
}

bool Validation::isValidStraightMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) {
    return true;
}

bool Validation::isValidDiagonalMove(Board& board, int fromRow, int fromCol, int toRow, int toCol) {
    return true;
}
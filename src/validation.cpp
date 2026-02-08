#include "validation.hpp"

bool Validation::isInBoard(int row, int col)
{
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE; 
}
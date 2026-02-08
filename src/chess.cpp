#include "chess.hpp"

void Chess::changePlayer()
{
    currentPlayer = currentPlayer == Color::white ? Color::black : Color::white;
}

void Chess::run()
{
    board.initBoard();
    board.printBoard(Color::white);
}
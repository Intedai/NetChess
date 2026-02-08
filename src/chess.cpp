#include "chess.hpp"

#define gameLoop while (true)

Chess::Chess()
    : board(), currentPlayer(Color::white) 
{
    board.initBoard();
}

void Chess::changePlayer() {
    currentPlayer = currentPlayer == Color::white ? Color::black : Color::white;
}

bool validateInput(std::string_view svInput, int& row, int& col)
{
    if (
        svInput.length() != 2 ||
        !std::isalpha(svInput[0]) ||
        !std::isdigit(svInput[1])
    )
        return false;
    
    char colChar = std::toupper(svInput[0]);
    if (colChar > 'H')
        return false;
    
    row = svInput[1] - '0' - 1;
    col = colChar - 'A';

    return true;
}

void Chess::run() {
    std::string input;
    
    int fromRow, fromCol;
    int toRow, toCol;

    gameLoop {
        board.printBoard(Color::white);
        do {
            std::cin >> input;
        } while (!validateInput(input, fromRow, fromCol));
        do {
            std::cin >> input;
        } while (!validateInput(input, toRow, toCol));

        board.movePiece(fromRow, fromCol, toRow, toCol);
    }
}
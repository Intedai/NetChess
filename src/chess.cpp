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

bool Chess::validateInput(std::string_view svInput, int& row, int& col)
{
    // Check if first char is A-H (or a-h) and if second char is 1-8

    // TODO: Do it better to avoid D.R.Y
    if (
        svInput.length() != 2 ||
        !std::isalpha(svInput[0]) ||
        !std::isdigit(svInput[1])
    ) {
        std::cout << "BAD INPUT! Try again" << std::endl;
        return false;
    }
    
    char colChar = std::toupper(svInput[0]);
    if (colChar > 'H') {
        std::cout << "BAD INPUT! Try again" << std::endl;
        return false;
    }
    
    row = svInput[1] - '0' - 1;
    col = colChar - 'A';

    return true;
}

void Chess::run() {
    std::string input;
    
    int fromRow, fromCol;
    int toRow, toCol;

    gameLoop {
        std::cout << "Current turn: " << colorToString(currentPlayer) << std::endl;
        board.printBoard(currentPlayer); // Kinda confusing, it's going to be used for online chess anyways

        do { // TODO: Turn into a function to avoid D.R.Y
            std::cin >> input;
        } while (!validateInput(input, fromRow, fromCol));

        // Check if the current player is allowed to move the piece he selected
        std::optional<Color> selectedPieceColor = board.getPieceColor(fromRow, fromCol);
        
        if (!selectedPieceColor || *selectedPieceColor != currentPlayer) {
            std::cout << "Must select your own piece" << std::endl;
            continue;
        }

        do {
            std::cin >> input;
        } while (!validateInput(input, toRow, toCol));
        

        board.movePiece(fromRow, fromCol, toRow, toCol);
        changePlayer();
    }
}
#include "board.hpp"

Board::Board()
{
    board.reserve(BOARD_SIZE);
    for (size_t r = 0; r < BOARD_SIZE; r++)
    {
        std::vector<Square> row;
        row.reserve(BOARD_SIZE);
        
        for (size_t c = 0; c < BOARD_SIZE; c++)
        {
            row.emplace_back();
        }

        board.push_back(std::move(row));
    }
}

void Board::initBoard()
{
    // King
    board[WHITE_PIECES_ROW][KING_POS].setPiece(std::make_unique<King>(Color::white));
    board[BLACK_PIECES_ROW][KING_POS].setPiece(std::make_unique<King>(Color::black));

    // Queen
    board[WHITE_PIECES_ROW][QUEEN_POS].setPiece(std::make_unique<Queen>(Color::white));
    board[BLACK_PIECES_ROW][QUEEN_POS].setPiece(std::make_unique<Queen>(Color::black));

    // Rooks
    for (size_t pos : ROOK_POS)
    {
        board[WHITE_PIECES_ROW][pos].setPiece(std::make_unique<Rook>(Color::white));
        board[BLACK_PIECES_ROW][pos].setPiece(std::make_unique<Rook>(Color::black));
    }

    // Knights
    for (size_t pos : KNIGHT_POS)
    {
        board[WHITE_PIECES_ROW][pos].setPiece(std::make_unique<Knight>(Color::white));
        board[BLACK_PIECES_ROW][pos].setPiece(std::make_unique<Knight>(Color::black));
    }

    // Bishops
    for (size_t pos : BISHOP_POS)
    {
        board[WHITE_PIECES_ROW][pos].setPiece(std::make_unique<Bishop>(Color::white));
        board[BLACK_PIECES_ROW][pos].setPiece(std::make_unique<Bishop>(Color::black));
    }

    // Pawns
    for (size_t c = 0; c < BOARD_SIZE; c++)
    {
        board[WHITE_PAWN_ROW][c].setPiece(std::make_unique<Pawn>(Color::white));
        board[BLACK_PAWN_ROW][c].setPiece(std::make_unique<Pawn>(Color::black));
    }
}

void Board::printBoard(Color perspective) const{

    for(size_t i = 0; i < BOARD_SIZE; i++)
    {
        int r;

        if (perspective == Color::white)
        {
            r = BOARD_SIZE - 1 - i;
        }
        else
        {
            r = i;
        }

        std::cout << r + 1 << " ";
        for (const Square& x : board[r])
        {
            std::cout << x.getSymbol() << " ";
        }
        std::cout << std::endl;
    }

    char startingChar = 'A';
    std::cout << "+ ";

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        std::cout << static_cast<char>(startingChar + i) << " ";
    }
    std::cout << std::endl;
}

void Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    board[fromRow][fromCol].movePiece(board[toRow][toCol]);
}

std::optional<Color> Board::getPieceColor(int row, int col) const {
    return board[row][col].getColor();
}
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
    board[WHITE_PIECES_ROW][KING_POS].setPiece(std::make_unique<King>(WHITE));
    board[BLACK_PIECES_ROW][KING_POS].setPiece(std::make_unique<King>(BLACK));

    // Queen
    board[WHITE_PIECES_ROW][QUEEN_POS].setPiece(std::make_unique<Queen>(WHITE));
    board[BLACK_PIECES_ROW][QUEEN_POS].setPiece(std::make_unique<Queen>(BLACK));

    // Rooks
    for (size_t pos : ROOK_POS)
    {
        board[WHITE_PIECES_ROW][pos].setPiece(std::make_unique<Rook>(WHITE));
        board[BLACK_PIECES_ROW][pos].setPiece(std::make_unique<Rook>(BLACK));
    }

    // Knights
    for (size_t pos : KNIGHT_POS)
    {
        board[WHITE_PIECES_ROW][pos].setPiece(std::make_unique<Knight>(WHITE));
        board[BLACK_PIECES_ROW][pos].setPiece(std::make_unique<Knight>(BLACK));
    }

    // Bishops
    for (size_t pos : BISHOP_POS)
    {
        board[WHITE_PIECES_ROW][pos].setPiece(std::make_unique<Bishop>(WHITE));
        board[BLACK_PIECES_ROW][pos].setPiece(std::make_unique<Bishop>(BLACK));
    }

    // Pawns
    for (size_t c = 0; c < BOARD_SIZE; c++)
    {
        board[WHITE_PAWN_ROW][c].setPiece(std::make_unique<Pawn>(WHITE));
        board[BLACK_PAWN_ROW][c].setPiece(std::make_unique<Pawn>(BLACK));
    }
}

void Board::printBoard() const{
    for(const auto& row : board)
    {
        for (const Square& x : row)
        {
            std::cout << x.getSymbol() << " ";
        }
        std::cout << std::endl;
    }
}
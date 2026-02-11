#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <optional>
#include "validation.hpp"
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"
#include "pawn.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "bishop.hpp"

constexpr int BOARD_SIZE = 8;

constexpr size_t WHITE_PAWN_ROW = 1;
constexpr size_t BLACK_PAWN_ROW = BOARD_SIZE - 2;

constexpr size_t WHITE_PIECES_ROW = 0;
constexpr size_t BLACK_PIECES_ROW = BOARD_SIZE - 1;

constexpr size_t KING_POS = 4;
constexpr size_t QUEEN_POS = 3;
constexpr std::array<size_t, 2> ROOK_POS = {0,BOARD_SIZE - 1};
constexpr std::array<size_t, 2> KNIGHT_POS = {1,BOARD_SIZE - 2};
constexpr std::array<size_t, 2> BISHOP_POS = {2,BOARD_SIZE - 3};

class Board {
    private:
        std::vector<std::vector<Square>> board;
    public:
        Board();
        void initBoard();
        void printBoard(Color perspective) const;
        void movePiece(int fromRow, int fromCol, int toRow, int toCol);
        bool validMovePiece(int fromRow, int fromCol, int toRow, int toCol);
        std::optional<Color> getPieceColor(int row, int col) const;
};
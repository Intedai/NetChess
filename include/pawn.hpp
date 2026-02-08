#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"

class Pawn : public Piece {
    public:
        explicit Pawn(Color color) : Piece(color) {}
        std::string getSymbol() const override;
};
#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"

class Rook : public Piece {
    public:
        explicit Rook(Color color) : Piece(color) {}
        std::string getSymbol() const override;
};
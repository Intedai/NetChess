#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"

class King : public Piece {
    public:
        explicit King(Color color) : Piece(color) {}
        std::string getSymbol() const override;
};
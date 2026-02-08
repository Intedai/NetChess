#pragma once

#include <string>
#include "color.hpp"
#include "square.hpp"
#include "piece.hpp"

class Queen : public Piece {
    public:
        explicit Queen(Color color) : Piece(color) {}
        std::string getSymbol() const override;
};
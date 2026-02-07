#pragma once

#include <string>
#include "utils.hpp"
#include "square.hpp"
#include "piece.hpp"

class Knight : public Piece {
    public:
        explicit Knight(Color color) : Piece(color) {}
        std::string getSymbol() const override;
};
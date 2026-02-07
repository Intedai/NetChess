#pragma once

#include <string>
#include "utils.hpp"
#include "square.hpp"
#include "piece.hpp"

class Bishop : public Piece {
    public:
        explicit Bishop(Color color) : Piece(color) {}
        std::string getSymbol() const override;
};
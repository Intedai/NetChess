#pragma once

#include <string>
#include "utils.hpp"

class Piece {
    protected:
        Color color;
    public:
        explicit Piece(Color color) : color(color) {}
        virtual ~Piece() = default;
        Color getColor() const {return color;}
        virtual std::string getSymbol() const = 0;
};

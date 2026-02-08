#include "king.hpp"

std::string King::getSymbol() const {
    return color == Color::white ? "♔" : "♚";
}
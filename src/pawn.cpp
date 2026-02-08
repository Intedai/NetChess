#include "pawn.hpp"

std::string Pawn::getSymbol() const {
    return color == Color::white ? "♙" : "♟";
}
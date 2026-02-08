#include "knight.hpp"

std::string Knight::getSymbol() const {
    return color == Color::white ? "♘" : "♞";
}
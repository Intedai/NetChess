#include "rook.hpp"

std::string Rook::getSymbol() const {
    return color == Color::white ? "♖" : "♜";
}
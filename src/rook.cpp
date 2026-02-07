#include "rook.hpp"

std::string Rook::getSymbol() const {
    return color == WHITE ? "♖" : "♜";
}
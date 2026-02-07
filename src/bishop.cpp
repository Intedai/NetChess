#include "bishop.hpp"

std::string Bishop::getSymbol() const {
    return color == WHITE ? "♗" : "♝";
}
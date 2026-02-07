#include "queen.hpp"

std::string Queen::getSymbol() const {
    return color == WHITE ? "♕" : "♛";
}
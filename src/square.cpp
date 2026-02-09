#include "square.hpp"

void Square::setPiece(std::unique_ptr<Piece> piece) {
    this->piece = std::move(piece);
}

void Square::clearSquare() {
    this->piece = nullptr;
}

std::string Square::getSymbol() const {
    if (piece)
        return piece->getSymbol();
    return "X";
}

void Square::movePiece(Square& dest) {
    dest.setPiece(std::move(piece));
}

std::optional<Color> Square::getColor() const {
    if (this->piece)
    {
        return piece->getColor();
    }
    return {};
}
#pragma once

#include <string>
#include <memory>
#include "piece.hpp"

class Square {
private:
    std::unique_ptr<Piece> piece;
public:
    explicit Square() : piece(nullptr) {}
    
    void setPiece(std::unique_ptr<Piece> piece);
    void clearSquare();

    void moveSquare(Square& dest);

    std::string getSymbol() const;
};
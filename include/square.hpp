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

    std::string getSymbol() const;
};
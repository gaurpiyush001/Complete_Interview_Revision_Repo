#ifndef MOVE_H
#define MOVE_H

#include "Piece.h"

class Move {
private:
    Piece* piece;
    int destRow;
    int destCol;

public:
    Move(Piece* piece, int destRow, int destCol)
        : piece(piece), destRow(destRow), destCol(destCol) {}

    Piece* getPiece() const {
        return piece;
    }

    int getDestRow() const {
        return destRow;
    }

    int getDestCol() const {
        return destCol;
    }
};

#endif // MOVE_H

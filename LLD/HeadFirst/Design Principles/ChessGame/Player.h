#ifndef PLAYER_H
#define PLAYER_H

#include "Color.h"
#include "Board.h"
#include "Move.h"
#include "Piece.h"
#include "InvalidMoveException.h"

class Player {
private:
    Color color;

public:
    Player(Color c) : color(c) {}

    Color getColor() const {
        return color;
    }

    void makeMove(Board& board, const Move& move) {
        Piece* piece = move.getPiece();
        int destRow = move.getDestRow();
        int destCol = move.getDestCol();

        if (board.isValidMove(piece, destRow, destCol)) {
            int sourceRow = piece->getRow();
            int sourceCol = piece->getCol();
            board.setPiece(sourceRow, sourceCol, nullptr);
            board.setPiece(destRow, destCol, piece);
            piece->setRow(destRow);
            piece->setCol(destCol);
        } else {
            throw InvalidMoveException("Invalid move!");
        }
    }
};

#endif // PLAYER_H

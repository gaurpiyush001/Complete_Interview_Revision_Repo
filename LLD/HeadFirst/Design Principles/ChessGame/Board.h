#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <memory>
#include "Color.h"
#include "Piece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

class Board {
private:
    std::vector<std::vector<std::unique_ptr<Piece>>> board;

public:
    Board() {
        board.resize(8, std::vector<std::unique_ptr<Piece>>(8));
        initializeBoard();
    }

    void initializeBoard() {
        // White pieces
        board[0][0] = std::make_unique<Rook>(Color::WHITE, 0, 0);
        board[0][1] = std::make_unique<Knight>(Color::WHITE, 0, 1);
        board[0][2] = std::make_unique<Bishop>(Color::WHITE, 0, 2);
        board[0][3] = std::make_unique<Queen>(Color::WHITE, 0, 3);
        board[0][4] = std::make_unique<King>(Color::WHITE, 0, 4);
        board[0][5] = std::make_unique<Bishop>(Color::WHITE, 0, 5);
        board[0][6] = std::make_unique<Knight>(Color::WHITE, 0, 6);
        board[0][7] = std::make_unique<Rook>(Color::WHITE, 0, 7);

        for (int i = 0; i < 8; ++i) {
            board[1][i] = std::make_unique<Pawn>(Color::WHITE, 1, i);
        }

        // Black pieces
        board[7][0] = std::make_unique<Rook>(Color::BLACK, 7, 0);
        board[7][1] = std::make_unique<Knight>(Color::BLACK, 7, 1);
        board[7][2] = std::make_unique<Bishop>(Color::BLACK, 7, 2);
        board[7][3] = std::make_unique<Queen>(Color::BLACK, 7, 3);
        board[7][4] = std::make_unique<King>(Color::BLACK, 7, 4);
        board[7][5] = std::make_unique<Bishop>(Color::BLACK, 7, 5);
        board[7][6] = std::make_unique<Knight>(Color::BLACK, 7, 6);
        board[7][7] = std::make_unique<Rook>(Color::BLACK, 7, 7);

        for (int i = 0; i < 8; ++i) {
            board[6][i] = std::make_unique<Pawn>(Color::BLACK, 6, i);
        }
    }

    Piece* getPiece(int row, int col) const {
        if (row < 0 || row >= 8 || col < 0 || col >= 8) return nullptr;
        return board[row][col].get();
    }

    void setPiece(int row, int col, std::unique_ptr<Piece> piece) {
        if (row >= 0 && row < 8 && col >= 0 && col < 8) {
            board[row][col] = std::move(piece);
        }
    }

    bool isValidMove(Piece* piece, int destRow, int destCol) const {
        if (!piece || destRow < 0 || destRow >= 8 || destCol < 0 || destCol >= 8) {
            return false;
        }
        Piece* destPiece = getPiece(destRow, destCol);
        return (!destPiece || destPiece->getColor() != piece->getColor()) &&
               piece->canMove(*this, destRow, destCol);
    }

    bool isCheckmate(Color color) const {
        // TODO: Implement actual checkmate logic
        return false;
    }

    bool isStalemate(Color color) const {
        // TODO: Implement actual stalemate logic
        return false;
    }
};

#endif

#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <iostream>
#include <memory>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Move.h"
#include "Piece.h"
#include "Color.h"

class ChessGame {
private:
    Board board;
    std::vector<std::unique_ptr<Player>> players;
    int currentPlayer;

public:
    ChessGame() : currentPlayer(0) {
        players.push_back(std::make_unique<Player>(Color::WHITE));
        players.push_back(std::make_unique<Player>(Color::BLACK));
    }

    void start() {
        // Game loop
        while (!isGameOver()) {
            Player* player = players[currentPlayer].get();
            std::cout << (player->getColor() == Color::WHITE ? "White" : "Black") << "'s turn." << std::endl;

            try {
                Move move = getPlayerMove(*player);
                player->makeMove(board, move);
                currentPlayer = (currentPlayer + 1) % 2;
            } catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                std::cout << "Try again!" << std::endl;
                continue;
            }
        }

        displayResult();
    }

private:
    bool isGameOver() const {
        return board.isCheckmate(Color::WHITE) || board.isCheckmate(Color::BLACK) ||
               board.isStalemate(Color::WHITE) || board.isStalemate(Color::BLACK);
    }

    Move getPlayerMove(Player& player) {
        int sourceRow, sourceCol, destRow, destCol;

        std::cout << "Enter source row: ";
        std::cin >> sourceRow;
        std::cout << "Enter source column: ";
        std::cin >> sourceCol;
        std::cout << "Enter destination row: ";
        std::cin >> destRow;
        std::cout << "Enter destination column: ";
        std::cin >> destCol;

        Piece* piece = board.getPiece(sourceRow, sourceCol);
        if (piece == nullptr || piece->getColor() != player.getColor()) {
            throw std::invalid_argument("Invalid piece selection!");
        }

        return Move(piece, destRow, destCol);
    }

    void displayResult() const {
        if (board.isCheckmate(Color::WHITE)) {
            std::cout << "Black wins by checkmate!" << std::endl;
        } else if (board.isCheckmate(Color::BLACK)) {
            std::cout << "White wins by checkmate!" << std::endl;
        } else if (board.isStalemate(Color::WHITE) || board.isStalemate(Color::BLACK)) {
            std::cout << "The game ends in a stalemate!" << std::endl;
        }
    }
};

#endif

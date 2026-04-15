#ifndef CHESSGAMEDEMO_H
#define CHESSGAMEDEMO_H

#include "ChessGame.h"

class ChessGameDemo {
public:
    static void run() {
        ChessGame chessGame;
        chessGame.start();
    }
};

#endif // CHESSGAMEDEMO_H

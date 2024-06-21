#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "ChessBoard.h"

class ChessGame {
private:
    ChessBoard board;
    Color currentPlayer;

public:
    ChessGame() : currentPlayer(WHITE) {}

    void playGame() {
        while (true) {
            board.displayBoard();
            int startX, startY, endX, endY;
            std::cout << "Enter move (startX startY endX endY): ";
            std::cin >> startX >> startY >> endX >> endY;

            if (board.movePiece(startX, startY, endX, endY)) {
                switchPlayer();
            } else {
                std::cout << "Invalid move, try again." << std::endl;
            }
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == WHITE) ? BLACK : WHITE;
    }
};

#endif // CHESSGAME_H

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>
#include "ChessPiece.h"

class ChessBoard {
private:
    std::vector<std::vector<ChessPiece*>> board;

public:
    ChessBoard() {
        board.resize(8, std::vector<ChessPiece*>(8, nullptr));
        setupBoard();
    }

    ~ChessBoard() {
        for (auto& row : board)
            for (auto& piece : row)
                delete piece;
    }

    void setupBoard() {
        // Initialize the board with pieces in their starting positions
        // For brevity, this example includes only kings
        board[0][4] = new King(WHITE);
        board[7][4] = new King(BLACK);
        // Add other pieces similarly
    }

    void displayBoard() {
        for (int y = 7; y >= 0; --y) {
            for (int x = 0; x < 8; ++x) {
                if (board[y][x])
                    std::cout << board[y][x]->getSymbol() << " ";
                else
                    std::cout << ". ";
            }
            std::cout << std::endl;
        }
    }

    bool movePiece(int startX, int startY, int endX, int endY) {
        ChessPiece* piece = board[startY][startX];
        if (piece && piece->isValidMove(startX, startY, endX, endY)) {
            board[endY][endX] = piece;
            board[startY][startX] = nullptr;
            return true;
        }
        return false;
    }
};

#endif // CHESSBOARD_H

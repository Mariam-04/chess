#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <string>

enum PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE };
enum Color { WHITE, BLACK, NO_COLOR };

class ChessPiece {
protected:
    PieceType type;
    Color color;
    std::string symbol;
public:
    ChessPiece(PieceType type, Color color, const std::string& symbol)
        : type(type), color(color), symbol(symbol) {}

    virtual ~ChessPiece() {}

    PieceType getType() const { return type; }
    Color getColor() const { return color; }
    std::string getSymbol() const { return symbol; }

    virtual bool isValidMove(int startX, int startY, int endX, int endY) = 0;
};

class King : public ChessPiece {
public:
    King(Color color) : ChessPiece(KING, color, (color == WHITE) ? "♔" : "♚") {}

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        // Implement King move validation
        return abs(startX - endX) <= 1 && abs(startY - endY) <= 1;
    }
};

// Define other pieces (Queen, Rook, Bishop, Knight, Pawn) similarly
// For brevity, I'm skipping the full implementation here

#endif // CHESSPIECE_H

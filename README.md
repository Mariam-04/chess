
C++ Console Chess Game
This is a **simple console-based Chess game** written in C++. It uses object-oriented principles to simulate a chessboard, chess pieces, and game mechanics like move validation and turn switching.


Features

- 8×8 chessboard initialized with kings (extendable to all pieces).
- Turn-based gameplay (White starts).
- Move validation for each piece (currently implemented: King).
- Console interface to input moves.
- Displays the board after each move.
- Object-oriented structure:
  - `ChessPiece` (base class)
  - `King` (example derived class)
  - `ChessBoard` (board handling)
  - `ChessGame` (game loop logic)


Structure

ChessPiece.h    // Base class and piece definitions (King implemented)
ChessBoard.h    // 2D vector-based chessboard with setup and move logic
ChessGame.h     // Main game logic and player interaction
main.cpp        // Entry point to start the game

📌 Notes

- Currently, only the **King** is implemented.
- The code is designed for easy extension. You can add more pieces by:
  - Creating new classes (e.g., `Queen`, `Rook`) inheriting from `ChessPiece`
  - Implementing their `isValidMove()` logic
  - Placing them in `setupBoard()`
a

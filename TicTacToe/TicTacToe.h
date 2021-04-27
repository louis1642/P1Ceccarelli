#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <array>

class TicTacToe{
    private:
        enum Status{WIN, DRAW, CONTINUE};
        std::array<std::array<char, 3>, 3> board;
    public:
        TicTacToe();
        void makeMove();
        void printBoard() const;
        bool validMove(int, int) const;
        bool xoMove(char);
        Status gameStatus() const;
};

#endif
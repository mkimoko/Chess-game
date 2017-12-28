//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"


class Queen : public Piece{
private:
    Bishop m_bishop;
    Rook m_rook;
    void print();

public:
    Queen(Position position);
    Queen(int col, int row);
    int getCode();
    Bishop & getBishop();
    Rook & getRook();

    void positionement(Position position);
    int deplacement(Position position, int option);
    int specialMove(Position position);
    int kill(Piece * piece, int option);
};

#endif //CHESS_QUEEN_H

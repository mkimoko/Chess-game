//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Position position);
    Bishop(int col, int row);
    int getCode();
    int deplacement(Position position, int option);
    int specialMove(Position position);
    int kill(Piece * piece, int option);

private:
    void print();

};

#endif //CHESS_BISHOP_H

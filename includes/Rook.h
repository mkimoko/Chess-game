//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H


#include "Piece.h"

class Rook : public Piece{
public:
    int getCode();
    Rook(Position position);
    Rook(int col, int row);
    int deplacement(Position position, int option);
    int specialMove(Position position);
    int kill(Piece * piece, int option);

private:
    void print();
};


#endif //CHESS_ROOK_H

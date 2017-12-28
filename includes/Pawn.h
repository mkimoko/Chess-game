//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"

class Pawn : public Piece{

public:
    int getCode();
    Pawn( Position position);
    Pawn(int col, int row);
    int deplacement(Position position);
    int deplacement(Position position, int option);
    int specialMove(Position position);
    int kill(Piece & piece);

private:
    void print();
};


#endif //CHESS_PAWN_H

//
// Created by Mathieu on 18/12/2017.
//
#include "Piece.h"

#ifndef ECHEC_PAWN_H
#define ECHEC_PAWN_H


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


#endif //ECHEC_PAWN_H

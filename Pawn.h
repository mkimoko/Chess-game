//
// Created by Mathieu on 18/12/2017.
//
#include "Piece.h"

#ifndef ECHEC_PAWN_H
#define ECHEC_PAWN_H


class Pawn : public Piece{

    public:
        Pawn(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);

    private:
        void print();
};


#endif //ECHEC_PAWN_H
